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

Node *collision_point(Node *head1, Node *head2, int n){
    Node *temp1=head1;
    Node *temp2=head2;

    while(n>0){
        n--;
        temp1=temp1->next;
    }
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}
Node *intersection_Y_LL(Node *head1, Node *head2)
{
    Node *temp1=head1;
    Node *temp2=head2;
    Node *ans;
    int n1=0;
    int n2=0;

    while(temp1){
        n1++;
        temp1=temp1->next;
    }

    while(temp2){
        n2++;
        temp2=temp2->next;
    }

    if(n1>n2){
       ans= collision_point(head1,head2,n1-n2);
    }
    else{
        ans = collision_point(head2,head1,n2-n1);
    }
    return ans;
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