#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> NGE(vector<int>&nums1 , vector<int>&nums2){
        int n =nums2.size();
        vector<int>ans;
        map<int, int>mp;

        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]]=-1;
            }

            else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        
       for (int x : nums1) {
    ans.push_back(mp[x]);
}

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int>nums1={4,1,2};
    vector<int>nums2={1,3,4,2};
    vector<int>result=sol.NGE(nums1,nums2);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;

}