// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.


// Example 1

// Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

// Output: 3

// Explanation:

// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

// In no manner can we increase the minimum distance beyond 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int fit(vector<int>&nums , int mid){
        int i=1;
        int init =  0;
        int cnt=1;
        int n = nums.size();

        while(i<n){
            if((nums[i]-nums[init])>=mid){ 
                cnt++;
                init=i;
            }
           
            i++;
        }
        return cnt;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int low =1;
        int maximum = *max_element(nums.begin(),nums.end());
        int minimum = *min_element(nums.begin(),nums.end());

        int high = maximum-minimum;

        while(low<=high){
            int mid = low +(high-low) / 2;
            if(fit(nums,mid)<k){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};

int main(){
    vector<int>nums = {0,3,5,7,10,9};
    int k =6;
    Solution sol;
    sol.aggressiveCows(nums,k);
}