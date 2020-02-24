// [表示数值的字符串](https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2)
#pragma once
#define let const auto

namespace task53 {
    using namespace std;
    // start s0, +-1 s1, d1 s2, p1 s3, p2 s4, d2 s5, d3 s6, eE s7, +-2 s8, d4 s9, end s10, empty s11, error s12
// +- 0, d 1, . 2, eE 3, ^ 4, other 5, empty 6

    constexpr size_t trans[12][7] = {
            // +- 0, d 1, . 2, eE 3, ^ 4, other 5, empty 6
            {    1,   2,   4,   12,   12,  12,		0 }, // start
            {	 12,  2,   4,   12,   12,  12,		12 }, // +-1
            {	 12,  2,   3,   7,    10,  12,		11 }, // d1
            {	 12,  5,   12,  7,    10,  12,		11 }, // p1
            {    12,  6,   12,  12,   12,  12,		12 }, // p2
            {    12,  5,   12,  7,    10,  12,		11 }, // d2
            {	 12,  6,   12,  7,    10,  12,		11 }, // d3
            {    8,   9,   12,  12,   12,  12,		12 }, // eE
            {	 12,  9,   12,  12,   12,  12,		12 }, // +-2
            {	 12,  9,   12,  12,   10,  12,		11 }, // d4
            {    12,  12,  12,  12,   12,  12,		12 }, // end
            {	 12,  12,  12,  12,   10,  12,      11 } // empty
            // error
    };

    class Solution {
    public:
        bool isNumeric(char* string)
        {

            size_t pos = 0;
            size_t state = 0;
            while(true)
            {
                let ch = string[pos];
                size_t ch_index = 5;
                // +- 0, d 1, . 2, eE 3, ^ 4, other 5, empty 6
                if(ch=='+' || ch=='-')
                {
                    ch_index = 0;
                } else if(ch>='0' && ch<='9')
                {
                    ch_index = 1;
                } else if(ch=='.')
                {
                    ch_index = 2;
                } else if(ch=='e' || ch=='E')
                {
                    ch_index = 3;
                } else if(ch=='\0')
                {
                    ch_index = 4;
                } else if(ch==' ')
                {
                    ch_index = 6;
                } else
                {
                    ch_index = 5;
                }
                let next_state = trans[state][ch_index];
                if(next_state==10)
                {
                    return true;
                } else if(next_state==12)
                {
                    return false;
                } else
                {
                    state = next_state;
                    pos += 1;
                }
            }
        }
    };

}
