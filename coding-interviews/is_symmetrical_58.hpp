// [对称的二叉树](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb)
#pragma once

#include "util_tree_node.hpp"

namespace task58 {
    using namespace std;
    class Solution {
    public:
        bool isSymmetrical(TreeNode* pRoot)
        {
            return pRoot == nullptr || isSummetrical(pRoot->left, pRoot->right);
        }

        bool isSummetrical(TreeNode* left, TreeNode* right)
        {
            if(left==nullptr&&right==nullptr)
            {
                return true;
            }
            if(left==nullptr||right==nullptr)
            {
                return false;
            }
            if(left->val!=right->val)
            {
                return false;
            }
            return isSummetrical(left->left, right->right) && isSummetrical(left->right, right->left);
        }
    };
}
