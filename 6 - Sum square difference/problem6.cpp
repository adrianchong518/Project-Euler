#include <iostream>

#include "utils.h"

int main(int argc, char const *argv[]) {
  Timer timer;

  int max;
  if (argc < 2) {
    std::cerr << "Not enough arguments: Require a maximum limit\n";
    return -1;
  } else {
    max = atoi(argv[1]);
  }

  timer.startTimer();
  long long difference = 0;
  for (int i = 1; i <= max; i++) {
    for (int j = i + 1; j <= max; j++) {
      difference += i * j;
    }
  }
  difference *= 2;
  timer.endTimer();

  std::cout << "Difference: " << difference << '\n';
  std::cout << "Time taken: " << timer.time << " ms\n";

  return 0;
}
