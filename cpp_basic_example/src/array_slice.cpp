#include "array.h"
#include "spdlog/spdlog.h"


void array_example() {
    spdlog::info("Welcome to 数组使用!");
    double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    spdlog::info(sizeof(balance)/sizeof(double));
    int no_cap[]={1,2,3,4,5};
    spdlog::info(sizeof(no_cap)/sizeof(int));
    spdlog::info("循环数组");
    for (int i=0;i<5;i++) {
        spdlog::info(no_cap[i]);
    }
    // 替换值
    no_cap[0]=100;
    spdlog::info(no_cap[0]);
}

