// Given an integer array a of size n and an integer k. Split the array a into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.


// Example 1

// Input: a = [1, 2, 3, 4, 5], k = 3

// Output:6

// Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int split(vector<int>&nums, int mid){
        int cnt = 1;
        int pick = nums[0];
        int i=1;
        int n = nums.size();

        while(i<n){
            if(pick+nums[i]<=mid){
                pick += nums[i];
            }
            else{
                pick=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high-low) / 2;
            if(split(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout << sol.splitArray(nums, k) << endl; // Output: 18
    return 0;
}