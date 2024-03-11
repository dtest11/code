
#include <boost/asio.hpp>
#include <exception>
#include <iostream>
#include <ostream>

#include "client.cpp"
#include "server.cpp"

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }
    char server = 's';
    bool is_server{false};
    for (int i = 0; i < argc; i++) {
      std::cout << argv[i] << std::endl;
      if (*argv[i] == server) {
        std::cout << "server found" << std::endl;
        is_server = true;
      }
    }
    if (is_server) {
      run_server();
    } else {
      run_client(argc, argv);
    }

    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}