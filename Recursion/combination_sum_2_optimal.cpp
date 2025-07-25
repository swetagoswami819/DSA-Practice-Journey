#include<bits/stdc++.h>
using namespace std;


//combination sum 2 - optimal backtracking method ::-->
void subsequence(vector<int>&arr, int target, vector<int>&ds,vector<vector<int>>&ans, int index);

void sum(vector<int>&arr,int target){
    vector<int>ds;
    vector<vector<int>>ans;
    int index=0;
    subsequence(arr,target,ds,ans,index);

    for(auto it:ans){
        for(auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

void subsequence(vector<int>&arr, int target, vector<int>&ds,vector<vector<int>>&ans, int index){   //Base condition-->
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue; 

        if(arr[i]>target)  break;

        ds.push_back(arr[i]);

        subsequence(arr,target-arr[i],ds,ans,i+1);
        ds.pop_back();
    }


}
int main(){
    int n,x,k;
    vector<int>arr;
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
        
    }

    sum(arr,k);
    return 0;
}