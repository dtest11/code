#include <iostream>

#include "array_slice.h"
#include "spdlog/spdlog.h"
#include <catch2/catch_all.hpp>



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

void reverse_slice(int* int_slice,const size_t len) {
    spdlog::info("数组切片使用");
    size_t start = 0;
    size_t end = len - 1;
    while (start < end) {
        const int tmp = int_slice[start];
        int_slice[start] = int_slice[end];
        int_slice[end] = tmp;
        start++;
        end--;
    }
}
TEST_CASE("Reverse Slice Test", "[reverse_slice]") {
    // Test case 1: Reverse an array with even length
    SECTION("Even Length Array") {
        int arr[] = {1, 2, 3, 4};
        int expected[] = {4, 3, 2, 1};
        size_t len = sizeof(arr) / sizeof(arr[0]);

        reverse_slice(arr, len);

        for (size_t i = 0; i < len; i++) {
            REQUIRE(arr[i] == expected[i]);
        }
    }

    // Test case 2: Reverse an array with odd length
    SECTION("Odd Length Array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {5, 4, 3, 2, 1};
        size_t len = sizeof(arr) / sizeof(arr[0]);

        reverse_slice(arr, len);

        for (size_t i = 0; i < len; i++) {
            REQUIRE(arr[i] == expected[i]);
        }
    }
}