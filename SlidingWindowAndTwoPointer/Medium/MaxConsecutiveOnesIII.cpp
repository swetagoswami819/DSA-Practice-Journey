#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero=0;
        int maxi  = INT_MIN;

        int l =0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                zero++;
            } 
            
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }

            maxi = max(maxi , r-l+1);
            r++;
            
        }
        return maxi;
        
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Output: 6
    return 0;
}