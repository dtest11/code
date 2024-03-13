#include <ctime>
#include <iomanip>
#include <iostream>
#include <sys/timeb.h>
#include "spdlog/spdlog.h"

void time_example() {
    spdlog::info("time example");
    // get now
    // 基于当前系统的当前日期/时间

    // 把 now 转换为 tm 结构
    auto now = std::time(nullptr);
    auto local = std::localtime(&now);
    std::cout << std::put_time(local, "%Y-%m-%d %H:%M:%S") << std::endl;
    // 获取时间戳
    const auto timestamp = std::time(0); // s
    std::cout << "timestamp is:" << timestamp << std::endl;
    // 毫秒时间戳
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
        chrono::system_clock::now().time_since_epoch());
    std::cout << "timestamp is:" << ms.count() << std::endl;

    timeb t;
    ftime(&t);
    std::cout << t.time << std::endl; // 1710338857


    /**** 根据时间戳获取时间***/
    constexpr std::time_t unix_timestamp = 1710338857;
    std::chrono::system_clock::time_point time_point =
            std::chrono::system_clock::from_time_t(unix_timestamp);
    // 将时间点转换为本地时间
   const std::time_t local_time = std::chrono::system_clock::to_time_t(time_point);

    // 将本地时间转换为可读的日期时间字符串
    std::stringstream ss;
    ss << std::put_time(std::localtime(&local_time), "%Y-%m-%d %H:%M:%S");
    std::string datetime_str = ss.str();

    std::cout << "日期时间字符串: " << datetime_str << std::endl;
}
