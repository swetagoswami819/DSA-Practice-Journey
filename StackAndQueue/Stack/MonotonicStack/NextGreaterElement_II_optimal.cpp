#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> NGE(vector<int>&arr){
           int n =arr.size();
        vector<int>ans;
        stack<int>st;

        for(int i=(2*n-1);i>=0;i--){
            while(!st.empty() && st.top()<=arr[i%n]){
                st.pop();

            }

            if(i<n){
                st.empty()?ans.push_back(-1) : ans.push_back(st.top());
            }
            st.push(arr[i%n]);
        }
        reverse(ans.begin(),ans.end());
    
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