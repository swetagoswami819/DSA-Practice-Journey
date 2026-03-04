#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>powerSetBitManipulation(vector<int> &nums){
        int n = nums.size();
        int subsets = 1<<n;
        vector<int>row;
        vector<vector<int>>ans;

        for(int i=0;i<subsets;i++){
            int cnt = 0;
            while(cnt<n){
                if(i && (1<<cnt)){

                    row.push_back(nums[cnt]);
                    cnt++;
                }
            }

            ans.push_back(row);
        }

        return ans;
    }
};

int main(){
    vector<int>nums= {1, 2, 3};
    Solution sol;
    vector<vector<int>>ans  = sol.powerSetBitManipulation(nums);
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}