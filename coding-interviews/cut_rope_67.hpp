// [剪绳子](https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8)
#pragma once
#include <cstdint>
#include <cmath>

#define let const auto

namespace task67 {
    using namespace std;
    class Solution {
    public:
        int cutRope(int n) {
            if (n == 2) {
                return 1;
            }
            if (n == 3) {
                return 2;
            }
            int64_t x = n % 3;
            int64_t y = n / 3;
            if (x == 0) {
                return static_cast<int64_t>(pow(3, y));
            }
            else if (x == 1) {
                return 2 * 2 * static_cast<int64_t>(pow(3, y - 1));
            }
            else {
                return 2 * static_cast<int64_t>(pow(3, y));
            }
        }
    };
}
