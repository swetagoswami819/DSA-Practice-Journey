// Reverse LL in group of given size K

// Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.

// Do not change the values of the nodes, only change the links between nodes.


// Example 1

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

// Output: head -> 2 -> 1 -> 4 -> 3 -> 5

// Explanation: The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

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
    
    ListNode* reverseList(ListNode* head) {
    ListNode *prev=NULL;
    ListNode *temp=head;
    ListNode *node=head;

    while(temp){
        node=node->next;
        temp->next=prev;
        prev=temp;
        temp=node;
    }
    return prev;
        

    }

    ListNode* findKthNode(ListNode* temp , int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode * prevNode = NULL;
        ListNode *nextNode = NULL;
        while(temp!=NULL){
            ListNode* 
            kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode!=NULL){
                    prevNode->next = temp;
                }
                break;
            }

            nextNode =  kthNode->next;
            kthNode -> next = NULL;
            reverseList(temp);
            if(temp==head){
                head = kthNode;
            }
            else{
                prevNode ->next = kthNode;
            }
            prevNode =temp;
            temp = nextNode;
        
        }
        
        return head;
    }
};


int main(){

     // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;
    head = obj.reverseKGroup(head, k);

    // Print modified list
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}