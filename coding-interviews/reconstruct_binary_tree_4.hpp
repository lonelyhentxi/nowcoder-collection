// [重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6)
#pragma once
#include <unordered_map>
#include <vector>
#include "util_tree_node.hpp"

#define let const auto
using namespace std;

namespace task4 {
    class Solution {
    public:
        TreeNode* reConstructBinaryTree(const vector<int> &pre,const vector<int> &vin) {
            auto vp = vector<pair<int,size_t>>();
            size_t counter = 0;
            for(let v: vin) {
                vp.push_back({v, counter});
                counter ++;
            }
            let dict = unordered_map<int,size_t>(vp.begin(), vp.end());
            return reConstructBinaryTreeRec(dict, pre, vin, 0, 0, vin.size());
        }

        TreeNode* reConstructBinaryTreeRec(
                const unordered_map<int, size_t> &dict,
                const vector<int> &pre, const vector<int>&vin,
                const int pre_start, const int vin_start, const int vin_end)
        {
            if(vin_end - vin_start == 0) {
                return nullptr;
            }
            let current_val = pre[pre_start];
            TreeNode* current = new TreeNode (current_val);
            let vin_current_pos = dict.find(current_val) -> second;
            let left_vin_end = vin_current_pos;
            let right_vin_start = vin_current_pos + 1;
            let left_pre_start = pre_start + 1;
            let right_pre_start = left_pre_start + (left_vin_end - vin_start);
            current->left = reConstructBinaryTreeRec(dict, pre, vin, left_pre_start, vin_start, left_vin_end);
            current->right = reConstructBinaryTreeRec(dict, pre, vin,  right_pre_start, right_vin_start, vin_end);
            return current;
        }
    };
};
