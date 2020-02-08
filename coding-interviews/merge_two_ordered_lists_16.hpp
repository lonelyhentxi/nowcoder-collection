// [合并两个排序的链表](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337)
#pragma once
#include "util_list_node.hpp"

namespace task16 {
    using namespace std;

    class Solution {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            auto i=0;
            auto j=0;
            ListNode fake = ListNode(-1);
            ListNode* current = &fake;
            while(pHead1!=nullptr&&pHead2!=nullptr) {
                if(pHead1->val>pHead2->val) {
                    current->next = pHead2;
                    pHead2 = pHead2->next;
                }
                else {
                    current->next = pHead1;
                    pHead1 = pHead1->next;
                }
                current = current -> next;
            }
            if(pHead1!=nullptr) {
                current -> next = pHead1;
            }
            else if(pHead2!=nullptr) {
                current -> next = pHead2;
            }
            return fake.next;
        }
    };
}