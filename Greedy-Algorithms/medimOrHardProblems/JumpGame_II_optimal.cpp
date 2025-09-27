#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        int n=nums.size();

        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+nums[i]);
            }

            l=r+1;
            r=far;
            jumps++;


        }
        return jumps;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout<<sol.jump(nums)<<endl;
    return 0;
}