#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <boost/asio.hpp>
#include <functional>
#include <iostream>
#include <thread>

class printer {
 public:
  printer(boost::asio::io_context& io);
  ~printer();
  void print1();
  void print2();

 private:
  boost::asio::strand<boost::asio::io_context::executor_type> strand_;
  boost::asio::steady_timer timer1_;
  boost::asio::steady_timer timer2_;
  int count_;
};
#endif