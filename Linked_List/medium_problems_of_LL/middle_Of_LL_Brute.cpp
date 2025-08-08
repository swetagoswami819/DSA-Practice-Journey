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
Node * middle_LL(Node *head){
    Node *temp=head;
    int cnt=0;
    //find the no. of nodes--
    while(temp){
        cnt++;
        temp=temp->next;
    }
    int mid=(cnt/2)+1;
    temp=head;
    while(temp){
        mid-=1;
      
        if(mid==0){
            break;
        }
        temp=temp->next;
    }
    return temp;
}


int main(){
    vector<int> arr={2,5,7,3};
    Node * head=convertarr2LL(arr);
    Node * ans = middle_LL(head);
    cout<<ans->data<<" ";
    
}