// [把字符串转换成整数](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e)
#pragma once
#include <limits>
#include <cstdint>
#include <string>
#define let const auto

namespace task49 {
    using namespace std;
    constexpr int transfer[3][3] = {
            {1, 2,-1},
            {-1,2,-1},
            {-1,2,-1}
    };

    class Solution {
    public:
        int StrToInt(string str) {
            auto start_blanks = 0;
            while(str[start_blanks]==' ') {
                start_blanks ++;
            }
            str.erase(str.begin(), str.begin() + start_blanks);
            while(!str.empty()&&str.back()==' ') {
                str.pop_back();
            }
            auto pos = 0;
            auto state = 0;
            auto sign = 1;
            int64_t value = 0;
            while (pos<str.size()) {
                char ch = str[pos];
                int trans = 2;
                if(ch=='+' ) {
                    trans = 0;
                }
                else if(ch=='-') {
                    trans = 0;
                    sign = -1;
                } else if (ch >= '0' && ch <= '9') {
                    trans = 1;
                    value = 10 * value + (ch - '0');
                }
                state = transfer[state][trans];
                pos += 1;
                if(state==-1) {
                    return 0;
                }
            }
            if(state==2) {
                let res = sign * value;
                if(res < numeric_limits<int>::min() || res > numeric_limits<int>::max() ) {
                    return 0;
                }
                return sign * value;
            } else {
                return 0;
            }
        }
    };
}
