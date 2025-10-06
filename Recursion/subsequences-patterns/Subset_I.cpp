#include<bits/stdc++.h>
using namespace std;


class Solution{
    public : 

    void SubsetSum(int ind,int sum ,int n, vector<int>arr, vector<int>&ans){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        
       // sum=sum+arr[ind];
        SubsetSum(ind+1,sum+arr[ind],n,arr,ans);
       // sum=sum-arr[ind];
        SubsetSum(ind+1,sum, n, arr,ans);
        return;

    }
};
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    Solution sol;
    sol.SubsetSum(0, 0, 3,arr,ans);
    for(auto it : ans){
            cout << it << " ";
        cout << endl;
    }
    return 0;
}