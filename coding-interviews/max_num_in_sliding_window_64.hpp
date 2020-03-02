// [滑动窗口的最大值](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788)
#pragma once
#define let const auto
#include <queue>

namespace task64 {
    using namespace std;
    class Solution {
    public:
        vector<int> maxInWindows(const vector<int>& num, unsigned int size)
        {
            auto st = deque<int>{};
            auto res = vector<int>{};
            for(auto i=0; i<num.size(); i++)
            {
                let n = num[i];
                while(!st.empty() && (n >= num[st.back()] || st.back() <= i-static_cast<int>(size)))
                {
                    st.pop_back();
                }
                while(!st.empty() && st.front() <= i - static_cast<int>(size))
                {
                    st.pop_front();
                }
                st.push_back(i);
                if(i >= size-1)
                {
                    res.push_back(num[st.front()]);
                }
            }
            return res;
        }
    };
}
