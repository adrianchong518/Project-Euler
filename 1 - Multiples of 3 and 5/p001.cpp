#include <iostream>

int main(int argc, char* argv[]) {
  int sum = 0;
  int max = 10;

  if (argc >= 2) {
    max = atoi(argv[1]);
  }

  for (int i = 1; i < max; i++) {
    if (i % 5 == 0 | i % 3 == 0) {
      sum += i;
    }
  }

  std::cout << sum << '\n';

  return 0;
}