// [构建乘积数组](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46)
#pragma once

#include <vector>

namespace task51 {
    using namespace std;

    class Solution {
    public:
        vector<int> multiply(const vector<int> &A) {
            if (A.empty()) {
                return {};
            } else if (A.size() == 1) {
                return {1};
            }
            auto res = vector<int>(A.size(), 1);
            auto prod = 1;
            for (auto i = 1; i < A.size(); i++) {
                prod *= A[i - 1];
                res[i] *= prod;
            }
            prod = 1;
            for (int i = A.size() - 2; i >= 0; i--) {
                prod *= A[i + 1];
                res[i] *= prod;
            }
            return res;
        }
    };
}

