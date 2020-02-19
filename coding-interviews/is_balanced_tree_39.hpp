// [平衡二叉树](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222)
#pragma once
#include <cmath>
#include <algorithm>
#include "util_tree_node.hpp"

namespace task39 {
    using namespace std;
    class Solution {
    public:
        bool IsBalanced_Solution(TreeNode* pRoot) {
            if(pRoot==nullptr) {
                return true;
            }
            return height_rec(pRoot)!=-1;
        }

        // assume r not nullptr
        // if get -1, return immediately
        int height_rec(TreeNode* r) {
            auto lh = 0;
            if(r->left) {
                lh = height_rec(r->left);
                if(lh==-1) {
                    return -1;
                }
                lh += 1;
            }
            auto rh = 0;
            if(r->right) {
                rh = height_rec(r->right);
                if(rh==-1) {
                    return -1;
                }
                rh += 1;
            }
            if(abs(rh-lh)>1) {
                return -1;
            }
            return max(lh, rh);
        }
    };
}
