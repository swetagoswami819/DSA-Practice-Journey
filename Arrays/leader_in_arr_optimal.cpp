#include<bits/stdc++.h>
using namespace std;

vector<int> leaders_brute(vector<int>&arr, int n){
    vector<int>news;
    int j=0;
    news.push_back(arr[arr.size()-1]);
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]>news[j]){
            news.push_back(arr[i]);
            j++;
        }
    }


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