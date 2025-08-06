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

Node*  convertarr2LL(vector<int> &arr){
        Node *head= new Node(arr[0]);
        Node *mover=head;
        for(int i=1; i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            mover->next=temp;
            mover=mover->next;
            
        }
        return head;
        
    }

Node* deleteKthElement(Node *head,int val){
    if(head==NULL){
        return NULL;
    }
     
    Node *temp=head;
    if(head->data==val){
        head=head->next;
        free(temp);
        return head;    
    }

    else{
        Node *prev=NULL;
        while(temp!=NULL){
            
            if(temp->data==val){
                prev->next=prev->next->next;
                free(temp);
                return head;
            }
            prev=temp;
            temp=temp->next;

        }
    }

    return head;
}

Node * deleteNthNodeFromBackOfLL(Node *head,int n){
    if(head==NULL){
        return head;
    }

    Node *fast=head;
    Node *slow=head;
    while(n>0){
        fast=fast->next;
        n--;

    }
    
    if(fast==NULL){
        head=head->next;
        free(slow);
        return head;


    }
  
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
     
    Node *delNode=slow->next;
    slow->next=slow->next->next;
    free(delNode);
    return head;

}
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    head=deleteNthNodeFromBackOfLL(head,4);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}