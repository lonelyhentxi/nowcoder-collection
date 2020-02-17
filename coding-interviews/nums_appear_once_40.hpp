// [数组中只出现一次的数字](https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811)
#pragma once
#include <algorithm>
#include <vector>
#include <numeric>
#define let const auto

namespace task29 {
    using namespace std;
    class Solution {
    public:
        void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
            if(data.size()==0) {
                return;
            }
            if(data.size()==1) {
                *num1 = data[0];
                return;
            }
            let res = accumulate(data.begin(), data.end(), 0, [](int sum, const int curr) -> int { return (sum ^ curr);  } );
            auto pos_val = 0;
            for(auto i=0; i<sizeof(res)*8; i++) {
                let test = (1<<i);
                if ((res & test) != 0) {
                    pos_val = test;
                    break;
                }
            }
            if(pos_val==0) {
                return; // unreachable
            }
            auto temp1 = 0;
            auto temp2 = 0;
            for(let d: data) {
                if( d & pos_val ) {
                    temp1 ^=  d;
                } else {
                    temp2 ^=  d;
                }
            }
            *num1 = temp1;
            *num2 = temp2;
        }
    };
}
