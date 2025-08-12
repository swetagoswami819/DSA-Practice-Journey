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

Node *intersection_Y_LL(Node *head1, Node *head2)
{
    Node *temp1=head1;
    Node *temp2=head2;
  
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(temp1==NULL){
            temp1=head2;
        }
        if(temp2==NULL){
            temp2=head1;
        }
    }

    return temp1;

}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {8, 9};

    Node *head1 = convertarr2LL(arr1);
    Node *head2 = convertarr2LL(arr2);
    // Get pointer to the 3rd node of head1 (value 3)
     Node *temp1 = head1;
     while (temp1->data != 4)
         temp1 = temp1->next;

     // Get pointer to last node of head2
     Node *temp2 = head2;
     while (temp2->next)
         temp2 = temp2->next;

     // Link head2's last node to node with value 4 in head1
     temp2->next = temp1;
    Node *ans = intersection_Y_LL(head1, head2);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "No intersection" << endl;
    }
}