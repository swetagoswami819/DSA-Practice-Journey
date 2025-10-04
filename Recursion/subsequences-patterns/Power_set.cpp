#include<bits/stdc++.h>
using namespace std;


class Solution{
    public : 

    void powerSet(int ind,int n, vector<int>arr, vector<int>ds, vector<vector<int>>&ans){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[ind]);
        powerSet(ind+1,n,arr,ds,ans);
        ds.pop_back();
        powerSet(ind+1, n, arr,ds,ans);
        return;

    }
};
int main(){
    vector<int>arr={1,2,3};
    vector<int>ds;
    vector<vector<int>>ans;
    Solution sol;
    sol.powerSet(0, 3,arr,ds,ans);
    for(auto it : ans){
        for(auto num : it){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}