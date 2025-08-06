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
 

Node * insertBeforeKthNode(Node *head,int val, int k){
    if(k==1){
        return  insertBeforeHead(head,val);
    }
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node *prev=temp->back;
    Node * newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}
 
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    head=insertBeforeKthNode(head,15,1);

    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}