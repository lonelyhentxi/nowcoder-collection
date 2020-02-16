// [检查二叉搜索树后序遍历序列](VerifySquenceOfBST)
#pragma once
#define let const auto
#include <vector>
#include "util_tree_node.hpp"

namespace task23 {
    using namespace std;
    class Solution {
    public:
        bool VerifySquenceOfBST(const vector<int>& sequence) {
            if(sequence.size()==0) {
                return false;
            }
            return verifySequenceRec(sequence, 0, sequence.size());
        }

        bool verifySequenceRec(const vector<int>& sequence, size_t start, size_t end) {
            let len = end - start;
            if(len<=2) {
                return true;
            }
            let mid_val = sequence[end-1];
            auto mid_pos = end - 1;
            for(auto i=0;i < end - 1; i++) {
                let val = sequence[i];
                if(val<mid_val && mid_pos != end - 1) {
                    return false;
                }
                else if(val>mid_val && mid_pos == end - 1) {
                    mid_pos = i;
                }
            }
            return verifySequenceRec(sequence, start, mid_pos) && verifySequenceRec(sequence,mid_pos, end-1);
        }
    };
}