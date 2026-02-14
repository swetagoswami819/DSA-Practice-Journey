// Find Pairs with Given Sum in Doubly Linked List

// Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.



// Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.


// Example 1

// Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7

// Output: [[1, 6], [2, 5]]

// Explanation:

// 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

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

Node* findPairs(Node* head , int k){
    vector<pair<int,int>>v;
    Node* temp1 = head;
    while (temp1!=NULL)
    {
        Node* temp2 = temp1->next;
        while (temp2!=NULL && temp1->data+temp2->data<=k)
        {
            if(temp1->data+temp2->data==k){
                v.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    

};
 
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    head=findPairs(head , 5);

    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}