// [机器人的运动范围](https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8)
#pragma once
#include <vector>
#include <queue>

#define let const auto

namespace task66 {
    using namespace std;
    class Solution {
    public:
        int movingCount(int threshold, int rows, int cols)
        {
            if(threshold<=0 || rows<=0 || cols<=0 )
            {
                return 0;
            }
            auto map = vector<vector<bool>>(rows, vector<bool>(cols, false));
            map[0][0] = true;
            auto q = deque<pair<int, int>>{};
            q.push_back({ 0,0 });
            auto counter = 0;
            while(!q.empty())
            {
                let& front = q.front();
                let x = front.first;
                let y = front.second;
                if(is_valid(rows, cols, x - 1, y, threshold) && !map[x-1][y])
                {
                    map[x - 1][y] = true;
                    q.push_back({ x - 1, y });
                }
                if (is_valid(rows, cols, x + 1, y, threshold) && !map[x + 1][y])
                {
                    map[x + 1][y] = true;
                    q.push_back({ x + 1, y });
                }
                if (is_valid(rows, cols, x, y-1, threshold) && !map[x][y-1])
                {
                    map[x][y-1] = true;
                    q.push_back({ x, y-1 });
                }
                if (is_valid(rows, cols, x, y+1, threshold) && !map[x][y+1])
                {
                    map[x][y+1] = true;
                    q.push_back({ x, y+1 });
                }
                counter++;
                q.pop_front();
            }
            return counter;
        }

        inline int calc(int x, int y)
        {
            auto sum = 0;
            while(x)
            {
                sum += (x % 10);
                x /= 10;
            }
            while(y)
            {
                sum += (y % 10);
                y /= 10;
            }
            return sum;
        }

        inline bool is_valid(int rows, int cols, int x, int y, int threshold)
        {
            return (x >= 0 && x < rows && y>=0 && y < cols && calc(x, y)<=threshold);
        }
    };
}
