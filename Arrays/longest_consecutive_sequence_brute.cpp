#include<bits/stdc++.h>
using namespace std;

bool ls(vector<int>arr, int n){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}

int long_consecutive_sequence_brute(vector<int>&arr, int n){
    int longest=1;
    int cnt;
    for(int i=0;i<arr.size();i++){
        n=arr[i];
        cnt=1;

        while(ls(arr,n+1)==true){
            n=n+1;
            cnt++;
        }

        longest=max(longest,cnt);
    }
    return longest;

}
int main(){
    int n,x;
    cin>>n;

    vector<int>arr;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    int len=long_consecutive_sequence_brute(arr,n);
    cout<<len<<endl;

}