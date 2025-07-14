#include<bits/stdc++.h>
using namespace std;

vector<int> leaders_brute(vector<int>&arr, int n){
    vector<int>news;
    int j=0;
    for(int i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                break;
            }
            if(j==n-1){
                news.push_back(arr[i]);
            }
        }       
    }

    news.push_back(arr[n-1]);
    return news;
}

int main(){
    int n,x;
    cin>>n;

    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    vector<int>ans=leaders_brute(arr,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}