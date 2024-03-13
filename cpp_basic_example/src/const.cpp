#include <cstddef>
#include <iostream>
#include <ostream>
#include <termcolor/termcolor.hpp>

#include "color.h"

void const_param(const int n);

inline void const_example() {
  Green::PrintHeader("const example");
  int n1{10};
  int n2{100};
  const int n = 100;
  //  n == 10;  // 改了不起作用
  std::cout << n << std::endl;
  const_param(n);

  std::cout << termcolor::green << "<<<< const 使用在指针上" << std::endl;
  const int* pOne = &n1;  // 指向整形常量 的指针，它指向的值不能修改
  //*pOne = 1000;           // 它指向的值不能修改

  int* const pTwo =
      &n2;  // 指向整形的常量指针
            // ，它不能在指向别的变量，但指向（变量）的值可以修改。
  *pTwo = 1000;
  //   pTwo = &n1;它不能在指向别的变量

  const int* const pThree =
      nullptr;  // 指向整形常量 的常量指针
                // 。它既不能再指向别的常量，指向的值也不能修改。
  // 例如
  pOne = &n2;
  std::cout << "pone value" << *pOne << std::endl;
  pOne = &n2;
}

void const_param(const int n) {
  // n = 1000;// 编译不过去
  std::cout << n << std::endl;
}
