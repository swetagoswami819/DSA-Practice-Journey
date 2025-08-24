class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size=nums.size();
        int ans=0;
        int zero=0;
        int left=0;

        for(int right=0;right<size;right++){
            
            if(nums[right]==0){
                zero++;
            } 
            
            
        while(zero > 1) {
            if(nums[left] == 0) zero--;
            left++;
        }
            ans=max(ans,right-left); 

        }
        return ans;
        
    }
};