#pragma once

#include <ctime>
#include <iostream>

class Timer {
 private:
  clock_t start;
  clock_t end;

 public:
  double time;

 public:
  void startTimer();
  void endTimer();
};

void Timer::startTimer() { start = clock(); }

void Timer::endTimer() {
  end = clock();
  time = (double)(end - start) / CLK_TCK;
}