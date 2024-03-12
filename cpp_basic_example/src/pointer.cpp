#include <iostream>
#include <ostream>

#include "spdlog/spdlog.h"
using namespace std;

void update_value_by_pointer(int& i) {
  std::cout << "update_value_by_pointer:" << i << std::endl;
  // update i =1000
  i = 1000;
}

void update_value_by_pointer2(int* i) {
  std::cout << "update_value_by_pointer:" << i << std::endl;
  // update i =1000
  *i = 100000;
}

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
  // 引用
  int number = 1;
  int& number_ptr = number;

  std::cout << "number_ptr:" << number_ptr << std::endl;
  std::cout << "number_ptr:" << &number_ptr << std::endl;
  // update number
  number = 100;
  std::cout << "update number=100" << std::endl;
  std::cout << "number_ptr:" << number_ptr << std::endl;
  std::cout << "number_ptr:" << &number_ptr << std::endl;

  update_value_by_pointer(number);

  std::cout << "update number=100" << std::endl;
  std::cout << "number:" << number << std::endl;

  update_value_by_pointer2(&number);
  std::cout << "update number=1万" << std::endl;
  std::cout << "number:" << number << std::endl;
}
