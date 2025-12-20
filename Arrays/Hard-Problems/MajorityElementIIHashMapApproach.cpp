#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        int n = nums.size();
        int mn = (int)(n/3+1);
        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==mn){
                ans.push_back(nums[i]);
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> result = sol.majorityElement(nums);
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}