#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void left_rotate_by_d_place(vector<int>&arr,int d){
    int n=arr.size();
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());

}

int main(){

    vector<int>arr;
    int n,x,d;
    cin>>n;
    cin>>d;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);

    }

    left_rotate_by_d_place(arr,d);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;

}