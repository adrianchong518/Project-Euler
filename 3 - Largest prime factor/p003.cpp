#include <cmath>
#include <iostream>

#include "timer.h"

long findPrimeLargestFactor(long number) {
  long checkMax = 3;
  long possibleLargestFactor[2];

  checkMax = floorl(sqrtl(number));
  if (checkMax % 2 == 0) {
    checkMax--;
  }

  bool foundFactor = false;
  for (long i = checkMax; i >= 3 && !foundFactor; i -= 2) {
    if (number % i == 0) {
      possibleLargestFactor[0] = i;
      possibleLargestFactor[1] = number / i;
      foundFactor = true;
    }
  }

  if (!foundFactor && number % 2 == 0) {
    possibleLargestFactor[0] = 2;
    possibleLargestFactor[1] = number / 2;
    foundFactor = true;
  }

  if (foundFactor) {
    return std::max(findPrimeLargestFactor(possibleLargestFactor[0]),
                    findPrimeLargestFactor(possibleLargestFactor[1]));
  } else {
    return number;
  }
}

int main(int argc, char const *argv[]) {
  Timer timer;

  long number;

  if (argc < 2) {
    std::cerr << "Not enough arguments: Needed a numder to factorize...\n";
    return -1;
  } else {
    number = atol(argv[1]);
  }

  timer.startTimer();
  long largestPrimeFactor = findPrimeLargestFactor(number);
  timer.endTimer();

  std::cout << largestPrimeFactor << '\n';
  std::cout << "Time taken: " << timer.getDuration() << " ms\n";

  return 0;
}
