// [删除链表中重复的结点](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef)
#pragma once

#include <limits>
#include "util_list_node.hpp"

#define let const auto

namespace task56 {
    using namespace std;
    class Solution {
    public:
        ListNode* deleteDuplication(ListNode* pHead)
        {
            if(pHead==nullptr)
            {
                return nullptr;
            }
            ListNode fake_head = ListNode(numeric_limits<int>::min());
            fake_head.next = pHead;
            ListNode* processed = &fake_head;
            int current_val = pHead->val;
            ListNode* first_current_node = pHead;
            while(first_current_node->next != nullptr)
            {
                if(first_current_node->next->val!=current_val)
                {
                    processed = first_current_node;
                }
                else
                {
                    while(processed->next!=nullptr && processed->next->val==current_val)
                    {
                        let next_next = processed->next->next;
                        delete processed->next;
                        processed->next = next_next;
                    }
                    if(processed->next==nullptr)
                    {
                        break;
                    }
                }
                first_current_node = processed->next;
                current_val = first_current_node->val;
            }
            return fake_head.next;

        }
    };
}
