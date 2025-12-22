#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>zero;
        vector<int>one;
        vector<int>two;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if((nums[i]%3)==0){
                zero.push_back(nums[i]);
            }
            else if((nums[i]%3)==1){
                one.push_back(nums[i]);
            }
            else{
                two.push_back(nums[i]);
            }
        }

        sort(zero.begin(), zero.end(), greater<int>());
        sort(one.begin(), one.end(), greater<int>());
        sort(two.begin(), two.end(), greater<int>());

        if(zero.size()>=3){
            ans = max(ans , (zero[0]+zero[1]+zero[2]));
        }
        if(one.size()>=3){
            ans = max(ans, (one[0]+one[1]+one[2]));

        }
        if(two.size()>=3){
            ans = max(ans, (two[0]+two[1]+two[2]));
        
        }

        if(zero.size()>0 && one.size()>0 && two.size()>0){
        ans = max(ans ,  (zero[0]+one[0]+two[0]));
        }

        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {3,6,5,1,8};
    cout << sol.maximumSum(nums) << endl; // Output: 18
    return 0;
}