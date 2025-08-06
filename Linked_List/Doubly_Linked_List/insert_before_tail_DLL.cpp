#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node * next;
    Node *back;

    public :
    Node(int data1, Node* next1 , Node *back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public :
    Node(int data1){
        data=data1;
        next=NULL;
        back=NULL;
    }
};

Node*  convertarr2LL(vector<int> &arr){
        Node *head= new Node(arr[0]);
        Node *prev=head;
        for(int i=1; i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            prev->next=temp;
            temp->back=prev;
            prev=temp;
            
        }
        return head;
        
}

Node* insertBeforeHead(Node *head ,int val){
    Node* temp= new Node(val,head,NULL);
    head->back=temp;
    return temp;
     
}
 
Node* insertBeforeTail(Node *head ,int val){
       Node *tail=head;
       if(head->next==NULL){
            return insertBeforeHead(head,val);
       }
        while(tail->next!=NULL){
            tail=tail->next;
        }

        Node *prev=tail->back;
        Node *temp=new Node(val,tail,prev);
        prev->next=temp;
        tail->back=temp;
          
    return head;
}
 
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    head=insertBeforeTail(head,15);

    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}