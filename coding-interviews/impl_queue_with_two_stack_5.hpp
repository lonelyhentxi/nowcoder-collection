//[用两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6)
#pragma once
#include <stack>
#define let const auto

namespace task5 {
    using namespace std;

    class Solution {
    public:
        void push(int node) {
            stack1.push(node);
        }

        int pop() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    let val = stack1.top();
                    stack1.pop();
                    stack2.push(val);
                }
            }
            let res = stack2.top();
            stack2.pop();
            return res;
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
}
