#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include "color.h"

void read_file() {
  // open file
  std::ifstream fd;
  fd.open("./../src/file.cpp");
  if (!fd.is_open()) {
    std::cerr << "open file.cpp failed" << std::endl;
  }
  // read file line by line
  std::string line;
  // Read the file line by line
  int n{1};
  while (std::getline(fd, line)) {
    std::cout << "第" << n << "行" << line << std::endl;
    n++;
  }

  fd.close();
}
void write_file() {
  std::ofstream fd("./../src/hello.txt", std::ios::app);
  if (!fd.is_open()) {
    std::cerr << "open hello failed" << std::endl;
  }
  fd << "hello world" << std::endl;
  fd.close();
}
void file_example() {
  Green::PrintHeader("文件操作");
  read_file();
  write_file();
}
