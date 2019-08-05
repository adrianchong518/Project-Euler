#include <iostream>

#include "timer.h"

int main(int argc, const char *argv[]) {
  Timer timer;

  int a;
  int b;
  int c;

  std::cout << "Start finding the pythagorean triplet\n";
  bool found = false;

  timer.startTimer();
  for (a = 1; a < 250 && !found; a++) {
    for (b = 251; b < 500 && !found; b++) {
      c = 1000 - a - b;
      found = c * c == a * a + b * b;
    }
  }
  timer.endTimer();

  if (found) {
    a--;
    b--;

    std::cout << "Pythagorean triplet found: (" << a << ',' << b << ',' << c
              << ")\n";
    std::cout << "a * b * c = " << a * b * c << '\n';
  } else {
    std::cout << "Pythagorean triplet NOT FOUND\n";
  }
  std::cout << "Time taken: " << timer.getDuration() << " ms\n";

  return 0;
}