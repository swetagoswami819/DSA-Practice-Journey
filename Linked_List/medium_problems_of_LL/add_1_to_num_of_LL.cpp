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
   if(head==NULL || head->next==NULL){
        return head;
   }
   Node * newHead= reverse_LL(head->next);
   Node * front= head->next;
   front->next=head;
   head->next=NULL;
   return newHead;

}

Node * add_one_LL(Node * head){
    int sum;
    int carry=1;
    head=reverse_LL(head);  //O(n)
    Node *temp=head;
    Node *last=NULL;
    while(temp){     //O(n)
        temp->data=temp->data+carry;
        if(temp<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry!=0){
        Node * newNode=new Node(carry);
        last->next=newNode;
    }
    head=reverse_LL(head);   //O(n)
    return head;
}

int main(){
    vector<int> arr={9,9,9};
    Node * head=convertarr2LL(arr);
    head=add_one_LL(head);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}