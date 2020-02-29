// [序列化二叉树](https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84)
#pragma once
#include <vector>
#include <array>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>
#include <sstream>
#include "util_tree_node.hpp"

#define let const auto

namespace task61 {
    using namespace std;
    class Solution {
    public:
        char* Serialize(TreeNode* pRoot) {
            auto res = vector<string>{};
            auto qs = array<deque<TreeNode*>, 2>{};
            auto current_stack = 0;
            qs[current_stack].push_back(pRoot);
            while (!qs[current_stack].empty())
            {
                let another_stack = (current_stack + 1) % 2;
                while (!qs[current_stack].empty())
                {
                    let node = qs[current_stack].front();
                    if (node == nullptr)
                    {
                        res.push_back("#");
                    }
                    else
                    {
                        res.push_back(to_string(node->val));
                        qs[another_stack].push_back(node->left);
                        qs[another_stack].push_back(node->right);
                    }
                    qs[current_stack].pop_front();
                }
                current_stack = another_stack;
            }
            while (!res.empty() && res.back() == "#")
            {
                res.pop_back();
            }
            int all_length = max(1,accumulate(res.begin(), res.end(),
                                              0, [=](int len, const string& curr) -> int { return len + curr.size() + 1; }));
            let serialization = new char[all_length];
            size_t index = 0;
            for (auto i = 0; i < res.size(); i++)
            {
                for (auto j = 0; j < res[i].size(); j++)
                {
                    serialization[index] = res[i][j];
                    index++;
                }
                serialization[index] = ' ';
                index++;
            }
            serialization[all_length - 1] = '\0';
            return serialization;
        }
        TreeNode* Deserialize(char* str)
        {
            stringstream ss(str);
            string temp;
            ss >> temp;
            if(temp.empty())
            {
                return nullptr;
            }
            TreeNode* root = stotree(temp);
            bool addLeft = true;
            deque<TreeNode*> q = { root };
            while (!ss.eof())
            {
                ss >> temp;
                TreeNode* newNode = stotree(temp);
                let parent = q.front();
                if (addLeft)
                {
                    parent->left = newNode;
                }
                else
                {
                    parent->right = newNode;
                    q.pop_front();
                }
                addLeft = !addLeft;
                if (newNode != nullptr)
                {
                    q.push_back(newNode);
                }
            };
            return root;
        }

        // assume string not empty
        TreeNode* stotree(const string& s)
        {
            if (s[0] == '#')
            {
                return nullptr;
            }
            return new TreeNode(stoi(s));
        }
    };

}
