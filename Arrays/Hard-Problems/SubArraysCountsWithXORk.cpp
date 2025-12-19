#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithXORk(vector<int>&nums , int k){
    map<int,int>mp;
    int cnt = 0;
    int xr = 0;
    mp[0]++;  //{0,1} to handle the case when prefixXOR itself is k

    for(auto it  : nums){
        xr = xr ^ it;
        int x  = xr ^ k;

        cnt += mp[x];
        mp[xr]++; //if xr is present in map then it will increase its count or if its not present in map then it will insert xr with count 1 in map
    }
    return cnt;
}

int main(){
    vector<int>nums = {4,2,2,6,4};
    int k = 6;
    cout<<countSubarraysWithXORk(nums , k);
    return 0;
}