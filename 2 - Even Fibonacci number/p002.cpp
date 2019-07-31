#include <iostream>

int main(int argc, char const *argv[]) {
  const long start1 = 1;
  const long start2 = 1;

  long max = 100;
  long sum = 0;

  long prev1 = start1;
  long prev2 = start2;
  long current = prev1 + prev2;

  if (argc >= 2) {
    max = atol(argv[1]);
  }

  while (current <= max) {
    // Check if valid and add to sum
    if (current % 2 == 0) {
      sum += current;
    }

    // Generate next Fibonacci number
    prev1 = prev2;
    prev2 = current;
    current = prev1 + prev2;
  }

  std::cout << sum << '\n';

  return 0;
}