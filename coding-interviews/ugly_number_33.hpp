// [丑数](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b)
#pragma once
#include <vector>
#include <algorithm>


namespace task33 {
    using namespace std;
    class Solution {
    public:
        int GetUglyNumber_Solution(int index) {
            if(index<=0) {return 0;};
            auto res = vector<int>(index, 0);
            res[0] = 1;
            auto p2 = 0;
            auto p3 = 0;
            auto p5 = 0;
            for(auto i = 1; i<index; i++) {
                res[i] = min(res[p2] * 2, min(res[p3] * 3, res[p5] * 5));
                if(res[i]==res[p2]*2) p2++;
                if(res[i]==res[p3]*3) p3++;
                if(res[i]==res[p5]*5) p5++;
            }
            return res[index-1];
        }
    };
}