// [第一个只出现一次的字符](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c)
#pragma once
#define let const auto
#include <string>
#include <vector>

namespace task34 {
    using namespace std;

    class Solution {
    public:
        int FirstNotRepeatingChar(string str) {
            auto counter = vector<int>('z'-'A' + 1, -1);
            for(auto i=0;i<str.size();i++) {
                const int ci = str[i] - 'A';
                if(counter[ci]==-1) {
                    counter[ci] = i;
                } else if(counter[ci]>=0) {
                    counter[ci] = -2;
                }
            }
            int min_pos = str.size();
            for(let c: counter) {
                if(c>=0) {
                    min_pos = min(min_pos, c);
                }
            }
            return min_pos==str.size()?-1:min_pos;
        }
    };
}