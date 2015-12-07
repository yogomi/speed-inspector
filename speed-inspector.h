// Copyright 2014 Makoto Yano

#ifndef SPEED_INSPECTOR_H_
#define SPEED_INSPECTOR_H_

#include <iostream>
#include <string>
#include <chrono>

struct TimeInspector {
 public:
  static void setCurrentTime() {
    t_ = std::chrono::system_clock::now();
  }
  static void printTimeSpend(const std::string &message = std::string()) {
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(
                  std::chrono::system_clock::now() - t_).count()
              << " : " << message << std::endl;
    t_ = std::chrono::system_clock::now();
  }
 private:
  static std::chrono::system_clock::time_point t_;
};

std::chrono::system_clock::time_point TimeInspector::t_
                                          = std::chrono::system_clock::now();

#endif  // SPEED_INSPECTOR_H_
