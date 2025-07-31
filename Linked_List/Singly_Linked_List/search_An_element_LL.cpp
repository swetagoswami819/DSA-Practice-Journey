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

bool searchInLL(Node *head, int val){
    Node *temp=head;
    while(temp){
        if(temp->data==val){
            return true;
        }
    
        temp=temp->next;
    }
    return false;

}

int main(){
    vector<int> arr={2,5,8,7};
    Node * head=convertarr2LL(arr);
    bool ans=searchInLL(head, 5);
    cout << "Element found: " << (ans ? "Yes" : "No") << endl;
    return 0;

}