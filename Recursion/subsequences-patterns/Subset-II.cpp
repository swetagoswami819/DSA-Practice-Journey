#include<bits/stdc++.h>
using namespace std;

void SubsetSum(vector<int>&arr, vector<int>&ds,vector<vector<int>>&ans, int ind){
   
    ans.push_back(ds); //push every subset
    
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;

        ds.push_back(arr[i]);
        SubsetSum(arr,ds,ans,i+1);
        ds.pop_back();
   
    }
}

void sum(vector<int>&arr){
    sort(arr.begin(),arr.end()); //sorting is must
    vector<int>ds;
    vector<vector<int>>ans;
    int index=0;
    SubsetSum(arr,ds,ans,index);

    for(auto it:ans){
        for(auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}


int main(){
   vector<int>arr={1,2,3};


    return 0;
}