#include<bits/stdc++.h>
using namespace std;


int peak_element(vector<int>arr, int n){
    
    if(arr.size()==1) return arr[0];
    for(int i=0;i<n;i++){
        if((i==0 || arr[i]>arr[i-1])&&(i==n-1 || arr[i]>arr[i+1])){
            return arr[i];
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