// [从上往下打印二叉树](https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701)
#pragma once
#include <vector>
#include <deque>
#include "util_tree_node.hpp"
#define let const auto

namespace task22 {
    using namespace std;
    class Solution {
    public:
        vector<int> PrintFromTopToBottom(TreeNode* root) {
            auto res = vector<int>{};
            auto q = deque<TreeNode*>{};
            q.push_back(root);
            while(!q.empty()) {
                auto current = q.front();
                q.pop_front();
                if(current!=nullptr) {
                    res.push_back(current->val);
                    q.push_back(current->left);
                    q.push_back(current->right);
                }
            }
            return res;
        }
    };
}