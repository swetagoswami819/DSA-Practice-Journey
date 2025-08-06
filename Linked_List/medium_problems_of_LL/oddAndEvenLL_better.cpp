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

Node *oddAndEvenLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    int cnt = 1;
    Node *oddHead = new Node(-1);
    Node *evenHead = new Node(-1);

    Node *temp1 = oddHead;
    Node *temp2 = evenHead;
    Node *temp = head;

    while (temp != NULL)
    {
        if (cnt % 2 != 0)
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
        cnt++;
    }
    temp2->next = NULL;
    temp1->next = evenHead->next;
    return oddHead->next;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    Node *head = convertarr2LL(arr);
    head = oddAndEvenLL(head);
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}