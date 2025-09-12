#include <bits/stdc++.h>
using namespace std;

// Approach -1
/*class QueueUsingStack {
public:
    stack<int>s1;
    stack<int>s2;


    void push(int x) {
        int size=s1.size();
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
        } else {
            s1.pop();
        }
    }

    int top() {
        if (s1.empty()) {
            cout << "queue is empty" << endl;
            return -1;
        } else {
            return s1.top();
        }
    }

    int size() {
        return s1.size();
    }


};*/

// Approach -2
class QueueUsingStack
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int el;
        if (!s2.empty())
        {
            el = s2.top();
            s2.pop();
            return el;
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            el = s2.top();
            s2.pop();
        }
        return el;
    }

    int top()
    {
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size()
    {
        return s1.size() + s2.size();
    }

    bool isempty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    QueueUsingStack q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(8);

    q.pop();

    cout << "Top element: " << q.top() << endl;
    cout << "Stack size: " << q.size() << endl;

    return 0;
}
