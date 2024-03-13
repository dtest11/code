#define CATCH_CONFIG_RUNNER

#include <catch2/catch_all.hpp>

#include "array_slice.h"
#include "const.cpp"
#include "file.cpp"
#include "pointer.cpp"
#include "signal.cpp"
#include "string.cpp"
#include "time.cpp"

int main() {
  // return Catch::Session().run();
  array_example();
  string_example();
  pointer_example();
  time_example();
  const_example();
  file_example();
  sign_exampe();
  while (true){
    sleep(1);
  }
  return 0;
}