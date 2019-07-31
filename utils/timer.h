#pragma once

#include <chrono>

class Timer {
 private:
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;

  std::chrono::duration<long double, std::milli> duration;

 public:
  void startTimer();
  void endTimer();

  const long double getDuration();
};

void Timer::startTimer() {
  this->start = std::chrono::high_resolution_clock::now();
}

void Timer::endTimer() {
  this->end = std::chrono::high_resolution_clock::now();
  this->duration = this->end - this->start;
}

const long double Timer::getDuration() { return this->duration.count(); }