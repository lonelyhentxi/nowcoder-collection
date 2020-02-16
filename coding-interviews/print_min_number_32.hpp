// [把数组排成最小的数](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993)

#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#define let const auto


namespace task32 {
    using namespace std;
    class Solution {
    public:
        string PrintMinNumber(const vector<int>& numbers) {
            auto num_strs = vector<string>{};
            transform(numbers.cbegin(), numbers.cend(), back_inserter(num_strs),
                      [](int val) -> string { return std::to_string(val);});
            sort(num_strs.begin(), num_strs.end(),
                 [](const string& str1,const string& str2) {
                     string app1 = str1;
                     app1.append(str2);
                     string app2 = str2;
                     app2.append(str1);
                     return app1 < app2;
                 });
            return accumulate(num_strs.begin(), num_strs.end(), string{}, [](string sum, const string& cur) -> string{
                return std::move(sum) + cur;
            });
        }
    };
}