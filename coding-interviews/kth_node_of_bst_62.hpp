// [二叉搜索树的第k个结点](https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a)
#pragma once

#include "util_tree_node.hpp"

#define let const auto



namespace task62 {
    using namespace std;
    class Solution {
    public:
        TreeNode* KthNode(TreeNode* pRoot, int k)
        {
            return KthNodeRec(pRoot, k);
        }

        TreeNode* KthNodeRec(TreeNode* pRoot, int& k)
        {
            if (pRoot == nullptr)
            {
                return nullptr;
            }
            TreeNode* left_res = KthNodeRec(pRoot->left, k);
            if (left_res != nullptr)
            {
                return left_res;
            }
            k--;
            if (k == 0)
            {
                return pRoot;
            }
            return KthNodeRec(pRoot->right, k);
        }

    };
}
