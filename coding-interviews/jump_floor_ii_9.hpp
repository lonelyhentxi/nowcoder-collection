// [变态跳台阶](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387)
#pragma once
#include <vector>
#define let const auto

namespace task9 {
    using namespace std;
    class Solution {
    public:
        int jumpFloorII(int number) {
            auto dp = vector<int>(number+1, 0);
            dp[0] = 1;
            for(auto i=0;i<number;i++) {
                let now = dp[i];
                for(auto j=1;j<=number-i;j++) {
                    dp[i+j] += now;
                }
            }
            return dp[number];
        }
    };
}