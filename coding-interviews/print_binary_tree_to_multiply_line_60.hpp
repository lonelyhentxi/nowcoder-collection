// [把二叉树打印成多行](https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288)
#pragma once
#include <vector>
#include <array>
#include <queue>
#include "util_tree_node.hpp"

#define let const auto

namespace task60 {
    using namespace std;
    class Solution {
    public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            if (pRoot == nullptr)
            {
                return {};
            }
            auto qs = array<deque<TreeNode*>,2>{};
            auto current_stack = 0;
            qs[current_stack].push_back(pRoot);
            auto res = vector<vector<int>>{};
            while(!qs[current_stack].empty())
            {
                let another_stack = (current_stack + 1) % 2;
                auto new_layer = vector<int>{};
                while(!qs[current_stack].empty())
                {
                    let node = qs[current_stack].front();
                    new_layer.push_back(node->val);
                    if(node->left)
                    {
                        qs[another_stack].push_back(node->left);
                    }
                    if(node->right)
                    {
                        qs[another_stack].push_back(node->right);
                    }
                    qs[current_stack].pop_front();
                }
                res.push_back(std::move(new_layer));
                current_stack = another_stack;
            }
            return res;
        }

    };
}
