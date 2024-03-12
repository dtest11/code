#include <chrono>
#include <ctime>
#include <iomanip>

#include "spdlog/spdlog.h"

using namespace std;

void time_example() {
  spdlog::info("time example");
  // get now
  // 基于当前系统的当前日期/时间
  time_t now = time(0);

  // 把 now 转换为字符串形式
  char* dt = ctime(&now);

  cout << "本地日期和时间：" << dt << endl;

  // 把 now 转换为 tm 结构
  tm* gmtm = gmtime(&now);
  dt = asctime(gmtm);
  cout << "UTC 日期和时间：" << dt << endl;

  // std
  std::chrono::time_point<std::chrono::system_clock> now1 =std::chrono::system_clock::now();
  std::time_t time = std::chrono::system_clock::to_time_t(now1);
  std::ostringstream oss;
  oss << std::put_time(std::gmtime(&time), "%Y-%m-%dT%H:%M:%S%z");
  std::string timestamp = oss.str();
  timestamp.insert(timestamp.length() - 2, ":");
  std::cout<<timestamp<<std::endl;

}