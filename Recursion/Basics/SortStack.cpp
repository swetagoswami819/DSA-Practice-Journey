// Sort a Stack

// You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).


// Example 1

// Input: stack = [4, 1, 3, 2]

// Output: [4, 3, 2, 1]

// Explanation:

// After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.


#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    
    void insertVal(stack<int>& st, int val) {
        if (st.empty() || st.top() <= val) {
            st.push(val);
            return;
        }

        int x = st.top();
        st.pop();

        insertVal(st, val);

        st.push(x);
    }

    void sortStack(stack<int> &st) {
        if (st.empty()) return;

        int val = st.top();
        st.pop();

        sortStack(st);

        insertVal(st, val);
    }
};

int main() {
    stack<int> st;

   
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    Solution obj;
    obj.sortStack(st);

    cout << "Sorted Stack (top to bottom):" << endl;

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}