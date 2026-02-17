// Flattening of LL

// Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head
// Each of these child linked lists is in sorted order and connected by a 'child' pointer.



// Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.


// Example 1

// Input:

//Img of multilevel linked list

// Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12

// Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;

    ListNode(int x) {
        val = x;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:

    // Merge two sorted child lists
    ListNode* merge(ListNode* list1, ListNode* list2) {

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val <= list2->val) {
                temp->child = list1;
                list1 = list1->child;
            }
            else {
                temp->child = list2;
                list2 = list2->child;
            }

            temp = temp->child;
            temp->next = NULL;   // Important
        }

        if(list1) temp->child = list1;
        else temp->child = list2;

        return dummy->child;
    }

    // Flatten list using recursion
    ListNode* flattenALL(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        head->next = flattenALL(head->next);

        head = merge(head, head->next);

        return head;
    }
};


// Print using child pointer
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}


int main() {

    // Creating multi-level list
    // 1 -> 4 -> 7
    // |    |    |
    // 2    5    8
    // |    |    |
    // 3    6    9

    ListNode* head = new ListNode(1);
    head->child = new ListNode(2);
    head->child->child = new ListNode(3);

    head->next = new ListNode(4);
    head->next->child = new ListNode(5);
    head->next->child->child = new ListNode(6);

    head->next->next = new ListNode(7);
    head->next->next->child = new ListNode(8);
    head->next->next->child->child = new ListNode(9);

    Solution obj;
    ListNode* flatHead = obj.flattenALL(head);

    cout << "Flattened List: ";
    printList(flatHead);

    return 0;
}
