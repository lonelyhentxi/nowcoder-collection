// [连续子数组的最大和](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484)

#include <limits>
#define let const auto
#include <vector>
#include <algorithm>

namespace task30 {
    using namespace std;
    class Solution {
    public:
        int FindGreatestSumOfSubArray(vector<int> array) {
            auto all_max = numeric_limits<int>::min();
            auto last_max = numeric_limits<int>::min();
            for(auto i=0;i<array.size();i++) {
                last_max = std::max(last_max, 0) + array[i];
                all_max = std::max(last_max, all_max);
            }
            return all_max!=numeric_limits<int>::min()?all_max: 0 ;
        }
    };
}