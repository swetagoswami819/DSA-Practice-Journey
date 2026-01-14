// Minimum Number of Days to Make m Bouquets

// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int maximum(vector<int>nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);

    }
    return maxi;
}
    int countBouqet( vector<int> &nums, int day, int k, int m)
    {
        int flowers = 0;
        int bouqet = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= day)
            {
                flowers++;

                if (flowers == k)
                {
                    bouqet++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bouqet>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
          int ans=-1;
        int low=1;
        int high=maximum(nums);

        while(low<=high){
            int mid = low + (high - low)/2;


            if(countBouqet(nums,mid,k,m)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums =  {1,2,3,4};
    int m =2;
    int k =3;
    Solution sol;

    sol.minDays(nums,m,k);
}