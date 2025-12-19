#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[i]++;

        }
        
      
        for(auto &it : freq){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
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