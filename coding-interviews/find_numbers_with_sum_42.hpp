// [和为S的两个数字](https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b)
#pragma once
#include <unordered_set>
#include <queue>
#include <limits>
#include <vector>

namespace task42 {
    using namespace std;
    class Solution {
    public:
        vector<int> FindNumbersWithSum(vector<int> array,int sum) {
            auto mem = unordered_set<int>{};
            for(auto e: array) {
                mem.insert(e);
            }
            auto max_val = numeric_limits<int>::min();
            auto val1 = -1;
            auto val2 = -1;
            for(auto e: array) {
                if(mem.find(sum - e)!=mem.end()) {
                    max_val = max(max_val, e * (sum - e));
                    val1 = min(e, (sum - e));
                    val2 = max(e, (sum - e));
                }
            }
            return ((max_val==numeric_limits<int>::min()) ? vector<int>{} : vector<int>{val1, val2});
        }
    };
}
