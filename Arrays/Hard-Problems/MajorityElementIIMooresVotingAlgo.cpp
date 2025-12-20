#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        int el1=INT_MIN;
        int el2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        vector<int>ls;


        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2 = nums[i];

            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;

            else{
                cnt1--;
                cnt2--;
            } 

        }
        cnt1=0;
        cnt2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }

        int mn = (int)(n/3+1);
        if(cnt1>=mn){
            ls.push_back(el1);
        }
        if(cnt2>=mn){
            ls.push_back(el2);
        }

        return ls;
        
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