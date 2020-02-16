// [两个链表的第一个公共结点](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46)
#pragma once
#include <cmath>
#include "util_list_node.hpp"
#define let const auto

namespace task36 {
    using namespace std;
    class Solution {
    public:
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
            auto count1 = 0;
            auto count2 = 0;
            auto current1 = pHead1;
            auto current2 = pHead2;
            while(current1!=nullptr) {
                count1 ++;
                current1 = current1 -> next;
            }
            while(current2!=nullptr) {
                count2 ++;
                current2 = current2 -> next;
            }
            let sub = abs(count1 - count2);
            ListNode* fast = nullptr;
            ListNode* slow = nullptr;
            if(count1>count2){
                fast = pHead1;
                slow = pHead2;
            }
            else {
                fast = pHead2;
                slow = pHead1;
            }
            for(auto i=0;i<sub;i++){
                fast = fast -> next;
            }
            while(fast!=nullptr && slow!=nullptr){
                if(fast==slow) {
                    return fast;
                }
                fast = fast -> next;
                slow = slow -> next;
            }
            return nullptr;
        }
    };
}