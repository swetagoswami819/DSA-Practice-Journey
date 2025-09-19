#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> NSE(vector<int>&arr){
        int n =arr.size();
        vector<int>ans;

        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans.push_back(-1);
            }

            else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

int main(){
    Solution sol;
    vector<int>arr={4,5,2,10,8};
    vector<int>result=sol.NSE(arr);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;

}