// [数组中重复的数字](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8)
#pragma once
#define let const auto
#include <vector>

namespace task50 {
    using namespace std;
    class Solution {
    public:
        // Parameters:
        //        numbers:     an array of integers
        //        length:      the length of array numbers
        //        duplication: (Output) the duplicated number in the array number
        // Return value:       true if the input is valid, and there are some duplications in the array number
        //                     otherwise false
        bool duplicate(int numbers[], int length, int* duplication) {
            if (length <= 1) {
                return false;
            }
            auto count = vector<int>(length, 0);
            for(auto i=0 ; i<length;i++) {
                count[numbers[i]] ++;
                if(count[numbers[i]]>1) {
                    *duplication = numbers[i];
                    return true;
                }
            }
            return false;
        }
    };
}
