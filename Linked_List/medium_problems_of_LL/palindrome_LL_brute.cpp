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
 
 

bool palindrome_LL(Node * head){
    stack<int>st;
    Node *temp=head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp){
    if(temp->data!=st.top()){
        return false;
    }
    st.pop();
    temp=temp->next;
    }

    return true;


}
int main(){
    vector<int> arr={2,5,3,5,2};
    Node * head=convertarr2LL(arr);
    bool ans=palindrome_LL(head);
    cout<<ans<<" ";
    return 0;
}