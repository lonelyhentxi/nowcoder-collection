// [数据流中的中位数](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1)
#pragma once
#include <queue>
#define let const auto

namespace task63 {
    using namespace std;
    class Solution {
    private:
        size_t count;
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<> > larger;
        double mid;

    public:
        Solution() : count{0}, lower{}, larger{}, mid{ 0 } {}
        void Insert(int num)
        {
            if(count&1)
            {
                if (lower.empty() || num > lower.top())
                {
                    larger.push(num);
                    if(larger.size()>lower.size())
                    {
                        lower.push(larger.top());
                        larger.pop();
                    }

                }
                else
                {
                    lower.push(num);
                    if (lower.size() > larger.size())
                    {
                        larger.push(lower.top());
                        lower.pop();
                    }
                }
                mid = (static_cast<double>(larger.top()) + static_cast<double>(lower.top()))/2.0;
            } else
            {
                if (lower.empty() || num > lower.top())
                {
                    larger.push(num);
                    mid = larger.top();
                }
                else
                {
                    lower.push(num);
                    mid = lower.top();
                }
            }
            count += 1;
        }

        double GetMedian()
        {
            return mid;
        }

    };
}
