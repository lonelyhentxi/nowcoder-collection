// [二叉搜索树与双向链表](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5)
#pragma once
#include <tuple>
#define let const auto
#include "util_tree_node.hpp"

namespace task26 {
    using namespace std;
    class Solution {
    public:
        TreeNode* Convert(TreeNode* pRootOfTree)
        {
            let res = convert_rec(pRootOfTree);
            return res.first;
        }

        pair<TreeNode*,TreeNode*> convert_rec(TreeNode* current) {
            if(current==nullptr) {
                return {nullptr,nullptr};
            }
            let left_res = convert_rec(current->left);
            let right_res = convert_rec(current->right);
            if(right_res.first!=nullptr) {
                right_res.first -> left = current;
                current->right = right_res.first;
            }
            if(left_res.second!=nullptr) {
                left_res.second -> right = current;
                current->left = left_res.second;
            }
            return {
                    left_res.first!=nullptr?left_res.first: current,
                    right_res.second!=nullptr?right_res.second: current
            };
        }
    };
}