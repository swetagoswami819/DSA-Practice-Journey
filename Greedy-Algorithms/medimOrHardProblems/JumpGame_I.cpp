#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;

        for(int i=0;i<nums.size();i++){
            if(i>far) return false;
            far=max(far,(nums[i]+i));

        }
        
        return true;
        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout<<sol.canJump(nums)<<endl;
    return 0;
}
