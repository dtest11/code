#include <iostream>

#include "array_slice.h"
#include "spdlog/spdlog.h"


void array_example() {
    spdlog::info("Welcome to 数组使用!");
    double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    spdlog::info(sizeof(balance) / sizeof(double));
    int no_cap[] = {1, 2, 3, 4, 5};
    spdlog::info(sizeof(no_cap) / sizeof(int));
    spdlog::info("循环数组");
    for (int i = 0; i < 5; i++) {
        spdlog::info(no_cap[i]);
    }
    // 替换值
    no_cap[0] = 100;
    spdlog::info(no_cap[0]);
}

void reverse_slice(int* int_slice) {
    size_t len = sizeof(int_slice) / sizeof(int);
    spdlog::info("数组切片使用");
    size_t start = 0;
    size_t end = len - 1;
    while (start <= end) {
        const int a = int_slice[start];
        const int b = int_slice[end];
        const int tmp = b;
        int_slice[b] = a;
        int_slice[a] = tmp;
        start++;
        end--;
    }
}
