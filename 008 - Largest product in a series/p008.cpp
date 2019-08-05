#include <fstream>
#include <iostream>
#include <string>

#include "timer.h"

bool readNumberFromFile(const std::string& numberFileName,
                        std::string& number) {
  std::ifstream numberFile;
  numberFile.open(numberFileName);

  std::cout << "Reading number from file\n";

  if (numberFile.is_open()) {
    numberFile >> number;
  } else {
    std::cerr << "Failed to load number from file: Unable to open file\n";
    return false;
  }

  if (number.empty()) {
    std::cerr << "Failed to load number from file: File has no content\n";
    return false;
  }

  std::cout << "Done reading number from file\n";
  std::cout << "Number from file: " << number << '\n';

  return true;
}

int main(int argc, const char* argv[]) {
  Timer timer;

  int numConsecutiveNumbers;
  std::string numberFileName;
  std::string number;

  long greatestProduct = 0;
  int index;

  if (argc < 3) {
    std::cerr << "Not enough arguments: Required 2 arguments\n";
    return -1;
  } else {
    numConsecutiveNumbers = atoi(argv[1]);
    numberFileName = argv[2];
  }

  if (!readNumberFromFile(numberFileName, number)) {
    return -1;
  }

  std::cout << "Finding greatest product\n";
  timer.startTimer();
  for (std::string::iterator i = number.begin();
       i < number.end() - numConsecutiveNumbers; i++) {
    std::cout << "Checking index: " << i - number.begin() << '\n';
    long product = 1;

    for (std::string::iterator j = i; j < i + numConsecutiveNumbers; j++) {
      product *= *j - '0';
    }

    if (product > greatestProduct) {
      greatestProduct = product;
      index = i - number.begin();
    }
  }
  timer.endTimer();

  std::cout << "Greatest product found: " << greatestProduct << " (At index "
            << index << ")\n";
  std::cout << "Time taken: " << timer.getDuration() << " ms\n";

  return 0;
}
