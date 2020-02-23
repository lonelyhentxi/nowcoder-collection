// [正则表达式匹配](https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c)
#pragma once
#define let const auto
#include <vector>

namespace task52 {
    using namespace std;

    class Solution {
    public:
        inline size_t count_chars(char *str) {
            size_t length = 0;
            while (str[length] != '\0') {
                length++;
            }
            return length;
        }

        bool match(char *str, char *pattern) {
            let slength = count_chars(str);
            let plength = count_chars(pattern);
            auto dp = vector < vector < bool >> (slength + 1, vector<bool>(plength + 1, false));
            dp[0][0] = true;
            for (auto i = 0; i <= slength; i++) {
                for (auto j = 1; j <= plength; j++) {
                    if (j > 1 && pattern[j - 1] == '*') {
                        dp[i][j] = dp[i][j - 2] ||
                                   (i > 0 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j]);
                    } else {
                        dp[i][j] = i > 0 && dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
                    }
                }
            }
            return dp[slength][plength];
        }
    };
}
