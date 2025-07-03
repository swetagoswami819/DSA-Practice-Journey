#include<bits/stdc++.h>
using namespace std;

void permutation(int index,vector<int>& arr, vector<vector<int>>& ans);


void permute(vector<int> &arr){
    int index=0;
    
    vector<vector<int>>ans;
    permutation(index,arr,ans);
    
    for(auto it:ans){
        for (auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

void permutation(int index,vector<int>&arr, vector<vector<int>>&ans){
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i=index;i<arr.size();i++){
        
        swap(arr[i],arr[index]);
        permutation(index+1,arr,ans);
        swap(arr[i],arr[index]);
       

    }  
   
}
int main(){
    vector<int>arr;
    int n,x;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    permute(arr);


}