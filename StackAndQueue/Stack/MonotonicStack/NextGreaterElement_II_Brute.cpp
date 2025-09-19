#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> NGE(vector<int>&arr){
           int n =arr.size();
        vector<int>ans;
        stack<int>st;
        int ind;

       for(int i=0;i<n;i++){
        for(int j=i;j<i+n-1;j++){
            ind=j%n;
            if(arr[ind]>arr[j]){
                ans.push_back(arr[ind]);
                break;
            }

        }

       }
       return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums1={1,3,4,5,2,7};
    
    vector<int>result=sol.NGE(nums1);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;

}