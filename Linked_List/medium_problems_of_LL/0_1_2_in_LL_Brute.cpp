
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
    int cnt_0=0;
    int cnt_1=0;
    int cnt_2=0;
    Node *temp=head;

    while(temp){
        if(temp->data==0) cnt_0+=1;
        else if(temp->data==1) cnt_1+=1;
        else cnt_2+=2;
        temp=temp->next;
    }

   temp=head;
    while(temp){
        if(cnt_0!=0){
            temp->data=0;
            cnt_0-=1;
        }
        else if(cnt_1!=0){
            temp->data=1;
            cnt_1-=1;
        }
        else{
            temp->data=2;
            cnt_2-=1;
        }
        temp=temp->next;
    }

    return head;

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