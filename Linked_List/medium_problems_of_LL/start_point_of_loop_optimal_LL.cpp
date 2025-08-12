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
 
Node * detect_Loop(Node *head){
   Node *slow=head;
   Node *fast=head;
   while(fast!=NULL &&  fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        slow=head;
        while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
        }
        return slow;

    }
   } 

   return NULL;
}

int main(){
    vector<int> arr={2,5,4,7,3};
    Node * head=convertarr2LL(arr);
    Node* ans=detect_Loop(head);
    if(ans!=NULL){
        cout<<ans->data<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}