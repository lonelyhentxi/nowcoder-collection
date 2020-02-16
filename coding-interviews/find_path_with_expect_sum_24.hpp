// [二叉树中和为某一值的路径](https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca)
#pragma once
#include <algorithm>
#define let const auto
#include <util_tree_node.hpp>
#include <vector>

namespace task24 {
    using namespace std;
    class Solution {
    public:
        vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
            if(root==nullptr) {
                return {};
            }
            auto res = vector<vector<int>>{};
            find_path_rec(root, res, {}, expectNumber);
            std::sort(res.begin(), res.end(),  [](const vector<int>& a, const vector<int>& b) { return a.size() > b.size(); });
            return res;
        }

        // check root nullable out
        void find_path_rec(TreeNode* root, vector<vector<int>>& paths, vector<int> current_path, int target) {
            let remain_target= target - (root->val);
            current_path.push_back(root->val);
            if(root->left==nullptr && root->right==nullptr) {
                if(remain_target==0) {
                    paths.push_back(std::move(current_path));
                }
            }
            else {
                if(root->left!=nullptr) {
                    find_path_rec(root->left, paths, current_path, remain_target);
                }
                if(root->right!=nullptr) {
                    find_path_rec(root->right, paths, std::move(current_path),remain_target);
                }
            }
        }
    };
}