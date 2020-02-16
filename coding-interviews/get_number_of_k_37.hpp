// [数字在排序数组中出现的次数](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2)
#pragma once
#define let const auto
#include <vector>


namespace task37 {
    using namespace std;
    class Solution {
    public:
        int GetNumberOfK(vector<int> data ,int k) {
            auto begin = 0;
            auto end = data.size();
            auto count = 0;
            while(begin<end) {
                let mid = (begin + end)/2;
                if(data[mid] > k) {
                    begin = mid + 1;
                } else if(data[mid] < k) {
                    end = mid;
                } else {
                    auto j = mid;
                    while(j>=begin && data[j] == k) {
                        count ++;
                        j --;
                    }
                    j = mid + 1;
                    while(j < end && data[j] == k) {
                        count ++;
                        j++;
                    }
                    break;
                }
            }
            return count;
        }
    };
}