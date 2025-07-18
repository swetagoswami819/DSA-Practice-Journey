#include<bits/stdc++.h>
using namespace std;

int search_rotated_1_brute(vector<int>arr, int n, int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
}

}
int main(){
    int n,x,target;
    cin>>n;
    cin>>target;

    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
        int index=search_rotated_1_brute(arr,n,target);
        cout<<index;

}
