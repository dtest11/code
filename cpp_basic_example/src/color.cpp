#include "color.h"

#include <iostream>
#include <string>
#include <termcolor/termcolor.hpp>

void Green::PrintHeader(std::string str) {
  std::cout << termcolor::red << "------- " << str << "-------- " << std::endl;
}

void Green::PrintTitle(std::string str) {
  std::cout << termcolor::green << "<<<<  " << str << std::endl;
}