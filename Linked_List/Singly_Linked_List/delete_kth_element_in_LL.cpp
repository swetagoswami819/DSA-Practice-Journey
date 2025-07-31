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

Node * deleteKthElement(Node *head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node *temp=head;
    if(k==1){
        head=head->next;
        free(temp);
        return head;
        
    }

    else{
        Node *prev=NULL;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
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

 
int main(){
    vector<int> arr={2,5,8,7};
    int k=5;
    Node *head=convertarr2LL(arr);
    head=deleteKthElement(head,k);
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}