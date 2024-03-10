#include <functional>
#include <iostream>

#include "boost/asio.hpp"
#include "printer.h"

int main() {
  boost::asio::io_context io;
  printer p(io);
  std::thread t([&] { io.run(); });
  io.run();
  t.join();

  return 0;
}