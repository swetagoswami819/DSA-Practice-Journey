#include<bits/stdc++.h>
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

Node * convertarr2LL(vector<int> &arr){
        Node *head= new Node(arr[0]);
        Node *mover=head;
        for(int i=1; i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            mover->next=temp;
            mover=mover->next;
            
        }
        return head;
    }

Node * reverse_LL(Node *head){
    Node *prev=NULL;
    Node *temp=head;
    
    
    while(temp){
        Node * front =temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}


int main(){
    vector<int> arr={2,5,8,7};
    Node * head=convertarr2LL(arr);
    head=reverse_LL(head);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}