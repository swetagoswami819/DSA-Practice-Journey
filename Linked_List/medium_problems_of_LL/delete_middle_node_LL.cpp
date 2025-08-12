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
Node * delete_middle_LL(Node *head){
    Node *temp=head;
    int cnt=0;
     if(head==NULL || head->next==NULL){
        return NULL;
    }
    //find the no. of nodes--
    while(temp){
        cnt++;
        temp=temp->next;
    }
    int mid=(cnt/2);
    temp=head;
    while(temp){
        mid-=1;
      
        if(mid==0){
            break;
        }
        temp=temp->next;
    }
    Node *delNode=temp->next;
    temp->next=temp->next->next;
    free(delNode);
    return head;
}



int main(){
    vector<int> arr={2,5,4,7,3};
    Node * head=convertarr2LL(arr);
    head = delete_middle_LL(head);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }  
}