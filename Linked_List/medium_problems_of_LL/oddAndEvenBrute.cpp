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
     list<int>arr;
    Node *temp=head;
    //For the Odd indices--
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }

    if(temp){
        arr.push_back(temp->data);
    }


    //For the Even indices--
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }

    if(temp){
        arr.push_back(temp->data);
    }


    //push the elements back to the linked list--
    temp=head;
    for(auto it: arr){
        temp->data=it;
        temp=temp->next;
    }
    return head;
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