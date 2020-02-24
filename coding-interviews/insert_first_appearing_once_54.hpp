// [字符流中第一个不重复的字符](https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720)
#pragma once
#include <array>
#include <map>
#define let const auto

namespace task54 {
    using namespace std;




    class Solution
    {
    private:
        array<size_t, 256> order = array<size_t, 256> {};
        array<size_t, 256> counter = array<size_t, 256> {};
        map<size_t, char> once = map<size_t, char>{};
        size_t offset = 0;
    public:
        //Insert one char from stringstream
        void Insert(char ch)
        {
            let ch_index = static_cast<size_t>(ch);
            if(counter[ch_index]==0)
            {
                counter[ch_index] = 1;
                order[ch_index] = offset;
                once[offset] = ch;
                offset++;
            }
            else if(counter[ch_index]==1)
            {
                counter[ch_index] = 2;
                once.erase(order[ch_index]);
            }
        }
        //return the first appearence once char in current stringstream
        char FirstAppearingOnce()
        {
            let iter = once.begin();
            if(iter==once.end())
            {
                return '#';
            }
            return static_cast<char>(iter->second);
        }
    };
}
