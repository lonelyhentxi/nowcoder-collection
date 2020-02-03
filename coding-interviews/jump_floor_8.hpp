// [跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4)
#pragma once
#include <vector>
#define let const auto

namespace task8 {
    using namespace std;

    class Solution {
    public:
        int jumpFloor(int number) {
            auto dp = vector<int>(number+1, 0);
            dp[0] = 1;
            for(auto i=0;i<dp.size()-2;i++) {
                dp[i+1] += dp[i];
                dp[i+2] += dp[i];
            }
            dp[number] += dp[number-1];
            return dp[number];
        }
    };
}
