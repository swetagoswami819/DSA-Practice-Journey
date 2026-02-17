// Clone a LL with random and next pointer

// Given the head of a special linked list of n nodes where each node contains an additional pointer called 'random' which can point to any node in the list or null.



// Construct a deep copy of the linked list where,

// n new nodes are created with corresponding values as original linked list.
// The random pointers point to the corresponding new nodes as per their arrangement in the original list.
// Return the head of the newly constructed linked list.


// Note: For custom input, a n x 2 matrix is taken with each row having 2 values:[ val, random_index] where,

// val: an integer representing ListNode.val
// random_index: index of the node (0 - n-1) that the random pointer points to, otherwise -1.

// Example 1

// Input: [[1, -1], [2, 0], [3, 4], [4, 1], [5, 2]]

// Output: 1 2 3 4 5, true

// Explanation: All the nodes in the new list have same corresponding values as original nodes.

// All the random pointers point to their corresponding nodes in the new list.

// 'true' represents that the nodes and references were created new.

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node* temp = head;

        // STEP 1: Insert copy nodes in between
        while(temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }

        // STEP 2: Assign random pointers
        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // STEP 3: Separate original and copied list(connect next pointers of original list and copied list)
        temp = head;
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while(temp != NULL) {
            copyTail->next = temp->next;
            copyTail = copyTail->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

// Helper function to print list
void printList(Node* head) {
    while(head != NULL) {
        cout << "Value: " << head->val;

        if(head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;
        head = head->next;
    }
}

int main() {

    // Creating example list:
    // 1 -> 2 -> 3
    // Random:
    // 1 -> 3
    // 2 -> 1
    // 3 -> 2

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;        // 1 -> 3
    head->next->random = head;              // 2 -> 1
    head->next->next->random = head->next;  // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    Node* copiedHead = obj.copyRandomList(head);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}
