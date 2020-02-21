// [不用加减乘除做加法](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215)
#pragma once

namespace task48 {
    using namespace std;
    class Solution {
    public:
        int Add(int num1, int num2)
        {
            return (num2==0? num1: Add(num1^num2,( (num1 & num2) << 1) ));
        }
    };
}
