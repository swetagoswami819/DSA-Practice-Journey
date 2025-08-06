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

Node * zero_one_two_LL(Node *head){
    Node *zero_head=new Node(-1);
    Node *one_head=new Node(-1);
    Node *two_head= new Node(-1);
    Node *temp=head;
    Node *zero=zero_head;
    Node *one=one_head;
    Node *two=two_head;

    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp; 
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }

    zero->next=(one_head->next)?one_head->next : two_head->next;
    one->next=two_head->next;
    two->next=NULL;

    Node *newHead= zero_head->next;

    free(zero_head);
    free(one_head);
    free(two_head);

    return newHead;



}
int main()
{
    vector<int> arr = {1,0,1,2,0,2,1};
    Node *head = convertarr2LL(arr);
    head = zero_one_two_LL(head);
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}