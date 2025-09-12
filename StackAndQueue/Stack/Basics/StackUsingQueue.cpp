#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue {
public:
    queue<int> q;

    void push(int x) {
        int s = q.size();
        q.push(x);

        // Rotate the queue to simulate stack behavior
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            q.pop();
        }
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return q.front();
        }
    }

    int size() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(8);

    st.pop();

    cout << "Top element: " << st.top() << endl;
    cout << "Stack size: " << st.size() << endl;

    return 0;
}
