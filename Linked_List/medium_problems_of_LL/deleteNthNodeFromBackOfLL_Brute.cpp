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
    Node *temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    temp=head;
    if(cnt==n){
        head=temp->next;
        free(temp);
        return head;
    }
    int res=cnt-n;
    while(temp){
        res--;
        if(res==0){
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
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    head=deleteNthNodeFromBackOfLL(head,1);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}