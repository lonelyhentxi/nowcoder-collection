// [二叉树的下一个结点](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e)
#pragma once

#include "util_tree_node.hpp"

#define let const auto

namespace task57 {
    using namespace std;
    class Solution {
    public:
        TreeLinkNode* GetNext(TreeLinkNode* pNode)
        {
            return GetNext(pNode, nullptr);
        }

        TreeLinkNode* GetNext(TreeLinkNode*pNode, TreeLinkNode* from)
        {
            if(pNode==nullptr)
            {
                return nullptr;
            }
            else if(from==nullptr)
            {
                if(pNode->right!=nullptr)
                {
                    return MidTraversalFirst(pNode->right);
                } else
                {
                    return GetNext(pNode->next, pNode);
                }
            }
            else
            {
                if(from==pNode->left)
                {
                    return pNode;
                }
                else
                {
                    return GetNext(pNode->next, pNode);
                }
            }
        }

        TreeLinkNode* MidTraversalFirst(TreeLinkNode* pNode)
        {
            if(pNode==nullptr)
            {
                return nullptr;
            }
            let left_res = MidTraversalFirst(pNode->left);
            return left_res!=nullptr ? left_res : pNode;
        }
    };
}