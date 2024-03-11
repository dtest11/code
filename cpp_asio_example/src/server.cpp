#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <boost/system/detail/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <ctime>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

using boost::asio::ip::tcp;

std::string make_daytime_string() {
  using namespace std;
  time_t now = time(0);
  return ctime(&now);
}
void run_server() {
  try {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
    for (;;) {
      tcp::socket socket(io_context);
      acceptor.accept(socket);
      std::string msg = make_daytime_string();
      boost::system::error_code ignore_error;
      boost::asio::write(socket, boost::asio::buffer(msg), ignore_error);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}