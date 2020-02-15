// [整数中1出现的次数](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6)

#include <vector>
#include <numeric>

namespace task29 {
    using namespace std;
    class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n)
        {
            auto dp = vector<int>(n+1, 0);
            dp[0] = 0;
            for(auto i = 1; i <=n ; i++) {
                if(i % 10==1) {
                    dp[i] = dp[i/10] + 1;
                }
                else  {
                    dp[i] = dp[i/10];
                }
            }
            return std::accumulate(dp.begin(), dp.end(), 0, std::plus<>{});
        }
    };
}