import gdb

class _ReturnBreakpoint(gdb.Breakpoint):
    def stop(self):
        for breakpoint in self._siblings:
            if breakpoint.number != self.number:
                gdb.execute(f"d {breakpoint.number}")
        return True    

class _BreakReturn(gdb.Command):
    def __init__(self):
        super(_BreakReturn, self).__init__("break-return", gdb.COMMAND_USER)

    def invoke(self, arg, from_tty):
        function_name = gdb.selected_frame().name()
        source_file = gdb.selected_frame().find_sal().symtab.filename

        breakpoints = []
        with open(source_file) as o:
            for zero_based_index, line in enumerate(o.readlines()):
                if not 'return ' in line:
                    continue
                breakpoint = _ReturnBreakpoint(line=zero_based_index+1, temporary=True)
                breakpoints.append(breakpoint)

        for breakpoint in breakpoints:
            breakpoint._siblings = breakpoints

