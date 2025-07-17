#include<bits/stdc++.h>
using namespace std;

int long_consecutive_sequence_better(vector<int>&arr, int n){
    sort(arr.begin(),arr.end());

    int longest=1;
    int last_smaller;
    int cnt=0;

    

    for(int i=0;i<arr.size();i++){
        if(arr[i]-1==last_smaller){
            cnt++;
            last_smaller=arr[i];
        }
        else if(arr[i]!=last_smaller){
            cnt=1;
            last_smaller=arr[i];
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

    int len=long_consecutive_sequence_better(arr,n);
    cout<<len<<endl;

}