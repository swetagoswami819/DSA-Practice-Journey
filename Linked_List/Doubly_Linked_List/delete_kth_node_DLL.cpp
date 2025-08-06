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

Node * deleteKthNode(Node *node){
    
    Node *prev=node->back;
    Node *front=node->next;

    if(front!=NULL){
        front->back=prev;
    }
    prev->next=front;

}
 
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);

    deleteKthNode(head->next->next->next);
   
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     
     
}