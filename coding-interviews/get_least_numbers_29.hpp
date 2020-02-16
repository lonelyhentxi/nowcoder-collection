// [最小的K个数](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf)
#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#define let const auto

namespace task29 {
    using namespace std;
    class Solution {
    public:
        vector<int> GetLeastNumbers_Solution(const vector<int>& input, int k) {
            if(k<=0 || k>input.size()) {
                return {};
            }
            auto res = priority_queue<int, vector<int>>();
            for(auto &c: input) {
                if(res.size()<k) {
                    res.push(c);
                }
                else {
                    auto last_max = res.top();
                    res.pop();
                    if(last_max < c) {
                        res.push(last_max);
                    } else {
                        res.push(c);
                    }
                }
            }
            auto outer = vector<int>{};
            while(!res.empty()) {
                outer.push_back(res.top());
                res.pop();
            }
            reverse(outer.begin(), outer.end());
            return outer;
        }
    };
}

