// [链表中倒数第k个结点](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a)
#pragma once
#include "util_list_node.hpp"

namespace task14 {
    using namespace std;

    class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            ListNode* fast = pListHead;
            ListNode* slow = pListHead;
            for(auto i=0;i<k;i++){
                if(fast==nullptr) {
                    return nullptr;
                }
                fast = fast->next;
            }
            while(fast!=nullptr) {
                fast = fast -> next;
                slow = slow -> next;
            }
            return slow;
        }
    };
}