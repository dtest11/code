#include <iostream>
#include <ostream>
#include <termcolor/termcolor.hpp>

#include "color.h"
#include "spdlog/spdlog.h"

void const_param(const int n);
inline void const_example() {
  Green::PrintHeader("const example");

  const int n = 100;
  //  n == 10;  // 改了不起作用
  std::cout << n << std::endl;
  const_param(n);

  std::cout << termcolor::green << "<<<< const 使用在指针上" << std::endl;
}

void const_param(const int n) {
  // n = 1000;// 编译不过去
  std::cout << n << std::endl;
}
