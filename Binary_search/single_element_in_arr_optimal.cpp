#include<bits/stdc++.h>
using namespace std;


int single_element_optimal(vector<int>arr, int n){
    if(arr.size()==1 || arr[1]!=arr[0]){
        return arr[0];
    }
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1;
    int high=n-2;
    int mid;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        else if((mid%2==0 && arr[mid]==arr[mid+1]) ||(mid%2==1 && arr[mid]==arr[mid-1])){
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

    int ans=single_element_optimal(arr,n);
    cout<<ans;
    return 0;
}