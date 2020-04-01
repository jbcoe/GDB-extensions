#include <limits>
#include <array>
#include <random>

int Sum(const int *data, int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += data[i];
  }
  return sum;
}

int Max(const int *data, int size) {
  int max = std::numeric_limits<int>::min();
  for (int i = 0; i < size; ++i) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}

int main() {
  std::array<int,20> data;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> uniform_dist(1, 100);

  for(int i=0; i<data.size(); ++i)
    data[i] = uniform_dist(mt);

  int sum = Sum(data.data(), data.size());

  int max = Max(data.data(), data.size());

  if (sum == max) {
    return -1;
  }
}
