// [旋转数组的最小数字](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba)
#pragma once
#include <vector>

namespace task6 {
    using namespace std;

#define let const auto

    class Solution {
    public:
        // s < m < e
        // s< m > e
        // s > m< e
        int minNumberInRotateArray(const vector<int> &rotateArray) {
            if (rotateArray.empty()) return 0;
            int left = 0, right = rotateArray.size() - 1;
            while (left < right) {
                if (rotateArray[left] < rotateArray[right]) return rotateArray[left];

                int mid = left + (right - left) / 2;
                if (rotateArray[left] < rotateArray[mid])
                    left = mid + 1;
                else if (rotateArray[mid] < rotateArray[right])
                    right = mid;
                else {
                    ++left;
                }
            }
            return rotateArray[left];
        }
    };
}