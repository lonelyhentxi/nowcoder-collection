// [数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163)
#pragma once

#include <vector>
#include <unordered_map>
#define let const auto

namespace task28 {
    using namespace std;
    class Solution {
    public:
        int MoreThanHalfNum_Solution(const vector<int>& numbers) {
            auto dict = unordered_map<int, size_t>{};
            for(let i: numbers) {
                dict[i] ++;
            }
            for(let &d: dict) {
                if(d.second*2>numbers.size()) {
                    return d.first;
                }
            }
            return 0;
        }
    };
}