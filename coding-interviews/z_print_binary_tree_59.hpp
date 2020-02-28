// [按之字形顺序打印二叉树](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0)
#pragma once
#include <vector>
#include <array>
#include <stack>
#include "util_tree_node.hpp"

#define let const auto

namespace task59 {
    using namespace std;
    class Solution {
    public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            if (pRoot == nullptr)
            {
                return {};
            }
            auto qs = array<stack<TreeNode*>,2>{};
            auto current_stack = 0;
            qs[current_stack].push(pRoot);
            auto res = vector<vector<int>>{};
            while(!qs[current_stack].empty())
            {
                let another_stack = (current_stack + 1) % 2;
                auto new_layer = vector<int>{};
                while(!qs[current_stack].empty())
                {
                    let node = qs[current_stack].top();
                    new_layer.push_back(node->val);
                    if(current_stack==0)
                    {
                        if(node->left)
                        {
                            qs[another_stack].push(node->left);
                        }
                        if(node->right)
                        {
                            qs[another_stack].push(node->right);
                        }
                    }else
                    {
                        if (node->right)
                        {
                            qs[another_stack].push(node->right);
                        }
                        if (node->left)
                        {
                            qs[another_stack].push(node->left);
                        }
                    }
                    qs[current_stack].pop();
                }
                res.push_back(std::move(new_layer));
                current_stack = another_stack;
            }
            return res;
        }

    };
}
