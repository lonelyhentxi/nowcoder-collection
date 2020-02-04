// [矩形覆盖](https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6)
#pragma once
#include <vector>
#define let const auto

namespace task10 {
    using namespace std;
    class Solution {
    public:
        int rectCover(int number) {
            auto dp  = vector<int>(number+1,0);
            dp[1] = 1;
            dp[2] = 2;
            for(auto i=3;i<=number;i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[number];
        }
    };
}