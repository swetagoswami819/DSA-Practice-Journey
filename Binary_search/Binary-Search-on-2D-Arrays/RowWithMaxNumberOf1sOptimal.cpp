#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int lowerBound(vector<int>&arr , int n , int k){
        int low  = 0 ,high = n;
        int ans =n;
        while(low<=high){
            int mid  = (low+high)/2;

            if(arr[mid]>=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    int rowIndex(vector<vector<int>> &nums, int n, int m)
    {
        int index = -1;
        int max_cnt = 0;
        int cnt;
        int i, j;

        for (i = 0; i < n; i++)
        {
            cnt = m  - lowerBound(nums[i] , n , 1);

            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                index = i;
            }
        }
        return index;
    }
};

int main(){
    Solution sol;
    int n = 2;
    int m =2;
    vector<vector<int>>nums = {{0,0},{1,1}};
    cout<<sol.rowIndex(nums, n, m);
    return 0;
    
}