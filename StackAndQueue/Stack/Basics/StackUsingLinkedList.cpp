#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node * next;

    public :
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    public :
    Node(int data1){
        data=data1;
        next=NULL;
    }
};

class StackImplementationUsingLL {
public:
int size=0;
    Node* topIndex = NULL;
    

    void push(int x) {
        Node * newNode= new Node(x);
        
            newNode->next=topIndex;
            topIndex=newNode;
            size=size+1;
        
    }


    void pop() {
       if(topIndex==NULL){
        cout<<"Stack is Empty"<<endl;
       }
       else{
        Node * p=topIndex;
        topIndex=topIndex->next;
        free(p);
        size=size-1;
       }
    }

    int peek() {
        if(topIndex==NULL){
            cout<<"stack is empty! so, the peek element doesn't exist"<<endl;
            return -1;
        }
        else{
            return topIndex->data;
        }
    }

    int size() {       
        return size;

    }
};

int main() {
    StackImplementationUsingLL st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(8);
    st.pop();

    cout << "Top element: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;

    return 0;
}
