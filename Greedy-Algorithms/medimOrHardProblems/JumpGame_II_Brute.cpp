#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count_jumps(vector<int>& nums, int ind, int jumps){
        if(ind>=nums.size()-1) return jumps;

        int min_jumps=INT_MAX;

        for(int i=1;i<=nums[ind];i++){
            min_jumps=min(min_jumps,count_jumps(nums,ind+i,jumps+1));
        }

        return min_jumps;
    }
    int jump(vector<int>& nums) {
        int jumps=0;
        int ind=0;

        int ans = count_jumps(nums,ind,jumps);
        return ans;
    
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout<<sol.jump(nums)<<endl;
    return 0;
}