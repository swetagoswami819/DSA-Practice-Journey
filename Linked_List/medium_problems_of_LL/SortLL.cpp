#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

Node *convertarr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node * findMiddle(Node* head ){
        Node* slow = head;
        Node * fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;

    }

    Node * merge(Node * lefthead ,Node * righthead){
        Node * dummyNode=  new Node(-1);
        Node* ptr = dummyNode;

        while(lefthead!=NULL && righthead!=NULL){
            if(lefthead->data<=righthead->data){
                ptr->next=lefthead;
                ptr=ptr->next;
                lefthead=lefthead->next;
            }
            else{
                ptr->next=righthead;
                ptr=ptr->next;
                righthead=righthead->next;

            }
        }

        if(lefthead) ptr->next=lefthead;
        else ptr->next=righthead;

        return dummyNode->next;
    }
    Node* sortList(Node* head) {


        if(head==NULL || head->next==NULL) return head;
        Node* middle = findMiddle(head);
        Node* lefthead = head;
        Node* righthead = middle->next;
        middle->next= NULL;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge(lefthead ,righthead);
    }

int main()
{
    vector<int> arr = {1,0,1,2,0,2,1};
    Node *head = convertarr2LL(arr);
    head = sortList(head);
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}