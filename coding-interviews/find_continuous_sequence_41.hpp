// [和为S的连续正数序列](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe)
#pragma once
#include <cmath>
#define let const auto
#include <vector>

namespace task41 {
    using namespace std;
    class Solution {
    public:
        vector<vector<int> > FindContinuousSequence(int sum) {
            auto res = vector<vector<int> >{};
            for(auto ave=1;ave<=sum; ave++) {
                let n = sum * 2 / ave;
                if(n * ave!=sum*2 || (ave & 1)==(n & 1)) {
                    continue;
                }
                else {
                    auto start = -1;
                    let end = ave/2 + (n/2);
                    if(ave  & 1) {
                        start = ave/2 - (n/2 - 1);
                    }
                    else {
                        start = ave/2 - (n/2);
                    }
                    if(start<1) {
                        continue;
                    }
                    auto new_vec = vector<int>();
                    for(auto i=start;i<=end;i++) {
                        new_vec.push_back(i);
                    }
                    res.push_back(std::move(new_vec));
                }
            }
            return res;
        }
    };
}
