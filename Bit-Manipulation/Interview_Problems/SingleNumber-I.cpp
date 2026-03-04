#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>&nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        int ans = nums[0];
        for(int i=1;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int>nums= {1, 2, 2, 4, 3, 1, 4};
    Solution sol;
    cout<<sol.singleNumber(nums);
    return 0;
}