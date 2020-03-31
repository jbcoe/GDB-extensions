int MultipleReturnPoints(int x) {
  switch(x) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  }
  return -1;
}

int main() {
  for(int i=0; i<10; ++i)
    MultipleReturnPoints(i);
}
