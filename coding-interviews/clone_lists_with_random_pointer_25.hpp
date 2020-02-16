// [复杂链表的复制](https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba)
#pragma once
#define let const auto

namespace task25 {
    using namespace std;struct RandomListNode {
        int label;
        struct RandomListNode *next, *random;
        RandomListNode(int x) :
                label(x), next(nullptr), random(nullptr) {
        }
    };

    class Solution {
    public:
        RandomListNode* Clone(RandomListNode* pHead)
        {
            if(pHead == nullptr) {
                return nullptr;
            }
            RandomListNode *current = pHead;
            while(current!=nullptr) {
                RandomListNode* new_node = new RandomListNode(current->label);
                new_node -> next = current -> next;
                current -> next = new_node;
                current = current -> next -> next;
            }
            current = pHead;
            while(current!=nullptr) {
                RandomListNode *new_random = nullptr;
                if(current->random!=nullptr) {
                    new_random = current->random->next;
                }
                current -> next -> random = new_random;
                current = current->next->next;
            }
            current = pHead;
            RandomListNode *res = current -> next;
            while(current!=nullptr) {
                RandomListNode* origin_next = current->next->next;
                RandomListNode* new_next = nullptr;
                if(origin_next!=nullptr) {
                    new_next = origin_next -> next;
                }
                current -> next -> next = new_next;
                current -> next = origin_next;
                current = current -> next;
            }
            return res;
        }
    };
}