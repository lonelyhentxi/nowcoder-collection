// [从尾到头打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035)
#pragma once
#include <algorithm>
#include <vector>
#include "util_list_node.hpp"
#define let const auto


namespace task3 {
    class Solution {
    public:
        vector<int> printListFromTailToHead(ListNode* head) {
            ListNode* current  = head;
            auto res = vector<int>{};
            while(current!=nullptr) {
                res.push_back(current->val);
                current = current->next;
            }
            std::reverse(res.begin(), res.end());
            return res;
        }
    };
}