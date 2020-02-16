// [数组中的逆序对](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5)
#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#define let const auto

namespace task35 {
    using namespace std;
    class Solution {
    public:
        int InversePairs(vector<int> data) {
            auto temp = data;
            int64_t count = 0;
            merge_count(data.begin(), data.end(), temp.begin(), temp.end(), count);
            return static_cast<int>(count % 1000000007);
        }

        void merge_count(
                const vector<int>::iterator start, const vector<int>::iterator end,
                const vector<int>::iterator tstart, const vector<int>::iterator tend,
                int64_t& count) {
            if(end-start < 2) {
                return;
            }
            auto temp = vector<int>();
            let mid = start + (end-start)/2;
            let tmid = tstart + (end - start)/2;
            merge_count(start, mid, tstart, tmid, count);
            merge_count(mid, end, tmid, tend, count);
            auto i = start;
            auto j = mid;
            auto k = tstart;
            while (i<mid && j<end) {
                if(*i < *j) {
                    *k = *i;
                    k++;
                    i++;
                } else {
                    *k = *j;
                    count += mid - i;
                    j++;
                    k++;
                }
            }
            std::move(i, mid, k);
            std::move(j, end, k);
            std::move(tstart, tend, start);
        }
    };

}