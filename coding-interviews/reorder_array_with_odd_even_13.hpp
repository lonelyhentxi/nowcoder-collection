// [调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593)
#pragma once
#define let const auto

namespace task13 {
    using namespace std;

    class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            let len = array.size();
            if(len<2) {
                return;
            }
            auto counter = 0;
            for(auto e: array) {
                if(e&1) {
                    counter ++;
                }
            }
            auto res = vector<int>(len, 0);
            auto i=0;
            auto j = counter;
            for(auto e: array) {
                if(e&1) {
                    res[i] = e;
                    i+=1;
                }
                else {
                    res[j] = e;
                    j+=1;
                }
            }
            array = std::move(res);
        }
    };
}
