#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "timer.h"

void readPrimesFile(std::vector<unsigned long> &primes,
                    const std::string &primesFilename) {
  std::cout << "Reading primes from file: " << primesFilename << '\n';

  std::ifstream primesFile;
  primesFile.open(primesFilename);

  if (primesFile.is_open()) {
    unsigned long prime;
    while (primesFile >> prime) {
      primes.push_back(prime);
    }
  }

  primesFile.close();

  std::cout << "Done reading primes\n";
}

void writePrimesFile(const std::vector<unsigned long> &primes,
                     const std::string &primesFilename) {
  std::cout << "Writing primes to file: " << primesFilename << '\n';

  std::ofstream primesFile;
  primesFile.open(primesFilename, std::ios::out | std::ios::trunc);

  if (primesFile.is_open()) {
    for (unsigned long prime : primes) {
      primesFile << prime << '\n';
    }
  }

  primesFile.close();

  std::cout << "Done writing primes\n";
}

int main(int argc, char const *argv[]) {
  unsigned long indexOfPrime;

  bool hasPrimeFile = false;
  std::string primesFilename;

  std::vector<unsigned long> primes;
  unsigned long testForPrime;

  Timer timer;

  // Reading arguments
  if (argc < 2) {
    std::cerr << "Not enough arguments: Require the index of primes\n";
    return -1;
  } else {
    indexOfPrime = atol(argv[1]);

    if (argc >= 3) {
      hasPrimeFile = true;
      primesFilename = argv[2];
    }
  }

  // Populate primes vector with file (if provided)
  if (hasPrimeFile) {
    readPrimesFile(primes, primesFilename);
  }

  // Get the first number to test for primes
  if (!primes.empty()) {
    testForPrime = primes.back() + 2;
  } else {
    primes.push_back(2);
    testForPrime = 3;
  }

  // Checking for prime until prime at the index is found
  std::cout << "Start find primes\n";

  timer.startTimer();
  while (primes.size() < indexOfPrime) {
    bool isPrime = true;
    unsigned long testMax = floor(sqrt(testForPrime));

    for (unsigned long prime : primes) {
      if (prime > testMax) {
        break;
      }

      if (testForPrime % prime == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      primes.push_back(testForPrime);
    }

    std::cout << "Number: " << testForPrime << " | isPrime? " << isPrime
              << '\n';

    testForPrime += 2;
  }
  timer.endTimer();

  std::cout << "Prime " << indexOfPrime << " is found - "
            << primes[indexOfPrime - 1] << '\n';
  std::cout << "Time taken to calulate primes: " << timer.getDuration()
            << " ms\n";

  if (hasPrimeFile) {
    writePrimesFile(primes, primesFilename);
  }

  return 0;
}
