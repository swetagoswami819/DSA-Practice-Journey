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

Node *  convertarr2LL(vector<int> &arr){
        Node *head= new Node(arr[0]);
        Node *mover=head;
        for(int i=1; i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            mover->next=temp;
            mover=mover->next;
            
        }
        return head;
        
    }
 
Node * insert_kth_pos(Node *head,int val,int k){
    Node *newNode=new Node(val);
    if(head==NULL){
        if(k==1){
            return newNode;
        }
        else{
            return NULL;
        }
    }

    if(k==1){
        newNode->next=head;
        return newNode;

    }

    Node *temp=head;
    int cnt=0;
    while(temp!=NULL ){
        cnt++;
        if(cnt==k-1){
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;

}
int main(){
    vector<int> arr={2,5,8,7};
    int val=12;
    Node *head=convertarr2LL(arr);
    head=insert_kth_pos(head,val,2);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}