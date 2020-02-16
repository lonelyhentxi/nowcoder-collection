// [二叉树的深度](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b)
#pragma once
#include <algorithm>
#include "util_tree_node.hpp"

namespace task38 {
    using namespace std;
    class Solution {
    public:
        int TreeDepth(TreeNode* pRoot)
        {
            if(pRoot==nullptr) {
                return 0;
            }
            return 1 + depth_rec(pRoot);
        }

        // assume root not nullptr
        int depth_rec(TreeNode* root) {
            auto left_depth = 0;
            if(root->left) {
                left_depth = 1 + depth_rec(root->left);
            }
            auto right_depth = 0;
            if(root->right) {
                right_depth = 1 + depth_rec(root->right);
            }
            return max(left_depth, right_depth);
        }
    };
}