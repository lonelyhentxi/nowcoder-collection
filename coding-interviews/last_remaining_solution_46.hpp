// [孩子们的游戏\(圆圈中最后剩下的数\)](https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6)
#pragma once
#include <vector>
#define let const auto
namespace task46 {
    using namespace std;
    class Solution {
    public:
        int LastRemaining_Solution(int n, int m)
        {
            if(n<=0) {
                return -1;
            }
            auto res =  vector<int>(0);
            res.reserve(n);
            for(auto i=0; i<n; i++) {
                res.push_back(i);
            }
            auto pos = 0;
            while(res.size()>1) {
                pos  = (pos + m - 1) % res.size();
                res.erase(res.begin() + pos, res.begin() + pos + 1);
            }
            return res[0];
        }
    };
}
