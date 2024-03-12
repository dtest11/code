#include <iostream>

#include "spdlog/spdlog.h"
using namespace std;

void pointer_example() {
  spdlog::info("指针数组与数组指针");
  int* p;
  int runoobAarray[5] = {1, 2, 3, 4, 5};
  p = runoobAarray;  // p指向数组的第一个元素
  // 访问数组元素
  std::cout << "数组第一个的值: " << *(p) << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << "数组第的值: " << *(p + i) << std::endl;
  }

  cout << "使用 runoobAarray 作为地址的数组值 " << endl;
  for (int i = 0; i < 5; i++) {
    cout << "*(runoobAarray + " << i << ") : ";
    cout << *(runoobAarray + i) << endl;
  }
}