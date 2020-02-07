// [反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca)
#pragma once
#include "util_list_node.hpp"

namespace task15 {
    using namespace std;
    class Solution {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            ListNode* res  = nullptr;
            while(pHead!=nullptr) {
                ListNode* new_node = new ListNode(pHead->val);
                new_node->next = res;
                res = new_node;
                pHead = pHead -> next;
            }
            return res;
        }
    };
}