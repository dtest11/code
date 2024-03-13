#include <csignal>
#include <iostream>

#include "color.h"

void sign_handler(int n) { 
    std::cout << n << std::endl;
    exit(n);   }
void sign_exampe() {
  Green::PrintHeader("信号处理");
  signal(SIGINT, sign_handler);
}