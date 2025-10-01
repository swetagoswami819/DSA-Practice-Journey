#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int maximum(vector<int>nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);

    }
    return maxi;
}
int requiredTime(vector<int>nums, int hourly){
    int totalhrs=0;
    for(int i=0;i<nums.size();i++){
        totalhrs+=((nums[i] + hourly - 1)/hourly);
    }
    return totalhrs;
}
int minimumRateToEatBananas(vector<int> nums, int h) {
    int low=1;
    int high=maximum(nums);
    
    while(low<=high){
        int mid=(low+high)/2;
        int requiredtime= requiredTime(nums,mid);
        if(requiredtime<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    
    }
};

int main(){
    vector<int>nums={7,5,3,11};
    int h=8;
    Solution sol;
    int ans = sol.minimumRateToEatBananas(nums,h);
    cout<<ans<<endl;
     
}