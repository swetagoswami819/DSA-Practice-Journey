#include<bits/stdc++.h>
using namespace std;


//combination sum 2 -brute force method ::-->
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
    if(index==arr.size()){
        if(target==0){
            for(auto it:ans){
                if(ds==it){
                    return;
                }    
            }
            ans.push_back(ds);
            return;
        }
        return;
    }

    if(arr[index]<=target){
        ds.push_back(arr[index]);
        subsequence(arr,target-arr[index],ds,ans,index+1);
        ds.pop_back();
    }

    subsequence(arr,target,ds,ans,index+1);
 

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