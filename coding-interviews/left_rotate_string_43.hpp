// [左旋转字符串](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec)
#pragma once
#include <string>
#define let const auto

namespace task43 {
    using namespace std;

    class Solution {
    public:
        string LeftRotateString(string str, int n) {
            if(str.size()<=1 || n == 0) {
                return str;
            }
            let len = str.size();
            n = n % len;
            auto pos = 0;
            auto last = str[0];
            auto curr = str[0];
            auto count = 0;
            while(count<len) {
                pos = ( pos + len - n ) % len;
                curr = str[pos];
                str[pos] = last;
                last = curr;
                count ++;
            }
            return str;
        }
    };
}
