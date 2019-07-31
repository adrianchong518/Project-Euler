#include <iostream>

#include "utils.h"

Timer timer;

long long findLCM(const long long a, const long long b) {
  long long lcm;
  long long hcf;

  long long tempA = a;
  long long tempB = b;

  while (tempA != tempB) {
    if (tempA > tempB) {
      tempA -= tempB;
    } else {
      tempB -= tempA;
    }
  }

  hcf = tempA;
  lcm = (a * b) / hcf;

  return lcm;
}

int main(int argc, char const *argv[]) {
  long max;
  if (argc < 2) {
    std::cerr << "Not enough arguments: Require a maximum limit\n";
    return -1;
  } else {
    max = atol(argv[1]);
  }

  timer.startTimer();
  long long smallestMultiple = 1;
  for (long i = 2; i <= max; i++) {
    smallestMultiple = findLCM(smallestMultiple, i);
  }
  timer.endTimer();

  std::cout << "Smallest Multiple: " << smallestMultiple << '\n';
  std::cout << "Time taken: " << timer.time << " ms\n";

  return 0;
}
