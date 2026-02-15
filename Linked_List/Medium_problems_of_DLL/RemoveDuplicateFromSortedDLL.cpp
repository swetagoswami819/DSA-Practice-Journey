// Remove duplicated from sorted DLL

// Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.



// Return the head of the modified linked list.


// Example 1

// Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// Output: head -> 1 <-> 3 <-> 4 <-> 5

// Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// The underlined nodes were deleted to get the desired result.


#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp = head;
        ListNode* temp2 = temp->next;
        while(temp2!=NULL){
            if(temp->val==temp2->val){
                ListNode* nextNode = temp2->next;
                temp->next= nextNode;
                if(nextNode != NULL){
                nextNode->prev= temp;
                }
                delete temp2;
                temp2= nextNode;
            }
            else {
                temp= temp2;
                temp2 = temp2->next;
            }
        }
        return head;

    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating: 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(5);

    // Linking nodes
    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;

}