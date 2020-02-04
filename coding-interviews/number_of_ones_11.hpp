// [二进制中1的个数](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8)
#pragma once
#define let const auto

namespace task11 {
    using namespace std;
    class Solution {
    public:
        int  NumberOf1(int n) {
            size_t sum = 0;
            while(n) {
                sum++;
                n &= (n-1);
            }
            return sum;
        }
    };
}