#include <bits/stdc++.h>
using namespace std;

class StackImplementation {
public:
    int topIndex = -1;
    int st[10];

    void push(int x) {
        if (topIndex >= 9) {  // Max index is 9
            cout << "Stack overflow" << endl;
        } else {
            topIndex++;
            st[topIndex] = x;
        }
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack underflow" << endl;
        } else {
            topIndex--;
        }
    }

    int peek() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return st[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    StackImplementation st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(8);
    st.pop();

    cout << "Top element: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;

    return 0;
}
