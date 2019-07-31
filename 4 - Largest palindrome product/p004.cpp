#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

#include "timer.h"

bool isPalindrome(const std::string& number) {
  std::string reverseNumber(number.rbegin(), number.rend());
  return number.compare(reverseNumber) == 0;
}

int main(int argc, char const* argv[]) {
  Timer timer;

  int factorNumDigit;
  if (argc < 2) {
    std::cerr << "Not enough arguments: Needed a number of digits for the "
                 "factors...\n";
    return -1;
  } else {
    factorNumDigit = atoi(argv[1]);
  }

  long factorStart = powl(10, factorNumDigit - 1);
  long factorEnd = powl(10, factorNumDigit) - 1;
  long largestPalindrome = 0;

  std::cout << "Start finding largest palindromial number...\n";
  std::cout << "(By a bruteforce algorithm)\n";

  timer.startTimer();
  for (int i = factorStart; i <= factorEnd; i++) {
    for (int j = factorStart; j <= i; j++) {
      long number = i * j;
      std::string stringNumber = std::to_string(number);

      bool valid = isPalindrome(stringNumber);
      if (valid && number > largestPalindrome) {
        largestPalindrome = number;
      }

      // std::cout << "Number: " << number << " | " << valid << '\n';
    }
  }
  timer.endTimer();

  std::cout << "Largest Palindrome: " << largestPalindrome << '\n';
  std::cout << "Time taken: " << timer.getDuration() << " ms\n";

  return 0;
}
