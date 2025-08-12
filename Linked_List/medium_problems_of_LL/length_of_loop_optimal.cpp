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

int length_of_Loop(Node *head)
{
    Node *slow=head;
   Node *fast=head;
   int len=0;
   while(fast!=NULL &&  fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        fast=fast->next;
        while(slow!=fast){
            len++;
            fast=fast->next;
        }
        return len;
    } 
   } 

   return -1;
}

int main()
{
    vector<int> arr = {2, 5, 4, 7, 3};
    Node *head = convertarr2LL(arr);
    int ans = length_of_Loop(head);
    cout << ans << endl;
}