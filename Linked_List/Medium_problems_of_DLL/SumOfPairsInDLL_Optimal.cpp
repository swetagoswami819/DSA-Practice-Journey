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

Node* findlast(Node* head){
    Node* tail = head;
    while (tail->next!=NULL)
    {
        tail = tail->next;
    }
    return tail;
    
}
vector<pair<int,int>> findPairs(Node* head , int k){
    vector<pair<int,int>>v;
    Node* left = head;
    Node* right = findlast(head);
    while (left->data<right->data)
    {
        if(left->data+right->data==k){
            v.push_back({left->data,right->data});
            left = left->next;
            right= right->back;
        }
        else if(left->data+right->data<k){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }

    return v;
}
 
int main(){
    vector<int> arr={2,5,8,7};
    Node *head=convertarr2LL(arr);
    vector<pair<int,int>>v =findPairs(head , 5);

    for(auto it :v){
        cout<<it.first<<it.second<<endl;
    }
    return 0;
}