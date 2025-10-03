#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public :
    int data;
    ListNode * next;

    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }

    ListNode(int data1){
        data = data1;
        next = NULL;
    }
};

ListNode * convertarr2LL(vector<int> &arr){
        ListNode *head = new ListNode(arr[0]);
        ListNode *mover = head;
        for(int i = 1; i < arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = mover->next;
        }
        return head;
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode dummy(-1);
       ListNode *temp = &dummy;

       while(list1 && list2){
        if(list1->data < list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
       }

       if(list1) temp->next = list1;  
       if(list2) temp->next = list2;  
       return dummy.next; 
}


int main(){
    vector<int> arr1={2,5,8,7};
    vector<int>arr2={1,3,4,6};
    ListNode * head1=convertarr2LL(arr1);
    ListNode * head2=convertarr2LL(arr2);
    ListNode * head = mergeTwoLists(head1,head2);
    ListNode *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    return 0;
}