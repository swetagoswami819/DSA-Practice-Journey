//Prefix and Suffix product
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        int ans= INT_MIN;

        int pref=1;
        int suff=1;

        for(int i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;

            pref= pref * nums[i];
            suff= suff * nums[n-i-1];
            ans = max(ans  ,max(pref, suff));

        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {2,3,-2,4};
    cout<< sol.maxProduct(nums);
    return 0;
}