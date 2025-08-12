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
int carry_adder(Node *head){
    if(head==NULL){
        return 1;
    }

    int carry=rev(head->next);
    head->data=head->data+carry;
    if(head->data<10){
        return 0;
    }
    else{
        head->data=0;
        return 1;
}

}
Node * add_one_LL(Node * head){
    int carry=carry_adder(head);
    if(carry==1){
        Node *newNode=new Node(1);
        newNode->next=head;
        head=newNode;
    }

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