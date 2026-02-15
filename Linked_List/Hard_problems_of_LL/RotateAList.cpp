// Rotate a LL

// Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.


// Example 1

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

// Output: head -> 4 -> 5 -> 1 -> 2 -> 3

// Explanation:

// List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

// List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode * temp=head;
        int  n =1;
        int cnt=1;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            n=n+1;
        }

        temp->next=head;

        k=k%n;
        temp=head;
        while(cnt!=(n-k)){
            temp=temp->next;
            cnt++;

        }
        head=temp->next;
        temp->next=NULL;

        return head;   
    }
};

int main(){
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k=2;

    Solution s;
    ListNode * ans = s.rotateRight(head,k);

    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}