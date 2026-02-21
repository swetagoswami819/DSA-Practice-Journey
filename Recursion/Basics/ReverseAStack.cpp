// Reverse a Stack

// You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.

// Your solution must modify the input stack in-place to reverse the order of its elements.

// Example 1

// Input: stack = [4, 1, 3, 2]

// Output: [2, 3, 1, 4]

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int a = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(a);
    }

    void reverseStack(stack<int> &st) {
        if (st.empty()) return;

        int val = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, val);
    }
};

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution obj;
    obj.reverseStack(st);

    cout << "Reversed Stack (top to bottom):\n";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}