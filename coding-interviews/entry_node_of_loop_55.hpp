// [链表中环的入口结点](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4)
#pragma once

#include "util_list_node.hpp"

namespace task55 {
    using namespace std;
    class Solution {
    public:
        ListNode* EntryNodeOfLoop(ListNode* pHead)
        {
            ListNode* fast = pHead;
            ListNode* slow = pHead;
            bool has_loop = false;
            while(fast!=nullptr)
            {
                if(fast->next==nullptr)
                {
                    break;
                }
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                {
                    has_loop = true;
                    break;
                }
            }
            if(!has_loop)
            {
                return nullptr;
            }
            ListNode* finder = pHead;
            while(finder!=slow)
            {
                finder = finder->next;
                slow = slow->next;
            }
            return finder;
        }
    };
}
