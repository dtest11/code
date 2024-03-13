#define CATCH_CONFIG_RUNNER

#include <catch2/catch_all.hpp>

#include "array_slice.h"
#include "pointer.cpp"
#include "string.cpp"
#include "time.cpp"
#include "const.cpp"

int main() {
  // return Catch::Session().run();
  array_example();
  string_example();
  pointer_example();
  time_example();
  const_example();
  return 0;
}