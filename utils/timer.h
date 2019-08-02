#pragma once

#include <chrono>

class Timer {
 public:
  void startTimer() { m_start = std::chrono::high_resolution_clock::now(); }

  void endTimer() {
    m_duration = std::chrono::high_resolution_clock::now() - m_start;
  }

  const long double getDuration() { return m_duration.count(); }

 private:
  std::chrono::high_resolution_clock::time_point m_start;

  std::chrono::duration<long double, std::milli> m_duration;
};