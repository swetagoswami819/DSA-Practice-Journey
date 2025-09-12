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

class QueueImplementationUsingLL {
public:
int size=0;
    Node *start=NULL;
    Node *end=NULL;

    void push(int x) {
        Node * newNode= new Node(x);
        if(start==NULL){
            start=newNode;
            end=newNode;
        }
        else{
            end->next=newNode;
            end=newNode;
        }
        size=size+1;
    }


    void pop() {
       if(start==NULL){
        cout<<"queue is empty"<<endl;
       }
       else{
        Node * p=start;
        start=start->next;
        free(p);
       }
    }

    int peek() {
        if(start==NULL){
            cout<<"Queue is empty! so, the peek element doesn't exist"<<endl;
            return -1;
        }
        else{
            return start->data;
        }
    }

    int size() { 
        return size;
    }
};

int main() {
    QueueImplementationUsingLL q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(8);
    q.pop();

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;

    return 0;
}
