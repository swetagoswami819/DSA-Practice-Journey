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

    ListNode() {
        val = 0;
        next = nullptr;
        child = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:

    // Convert sorted array to single vertical (child) linked list
    ListNode* convert(vector<int> &arr) {
        if(arr.size() == 0) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i = 1; i < arr.size(); i++) {
            temp->child = new ListNode(arr[i]);
            temp = temp->child;
        }

        return head;
    }

    // Flatten complete multi-level linked list
    ListNode* flattenALL(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* t2 = temp;

            while(t2 != NULL) {
                arr.push_back(t2->val);
                t2 = t2->child;
            }

            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        return convert(arr);
    }
};

// Helper function to print flattened list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {

    // Manually creating multi-level list
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
