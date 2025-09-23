#include<bits/stdc++.h>
using namespace std;


int peak_element(vector<int>arr, int n){

    int low=1;
    int high=n-2;
    int mid;
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return arr[mid];
        }
    
        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

     return -1;
}
int main(){

    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    int ans=peak_element(arr,n);
    cout<<ans;
    return 0;
}