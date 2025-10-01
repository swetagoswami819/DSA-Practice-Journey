#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int maximum(vector<int>nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);

    }
    return maxi;
}
    int countBouqet(int n, vector<int> &nums, int day, int k, int m)
    {
        int flowers = 0;
        int bouqet = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= day)
            {
                flowers++;

                if (flowers == k)
                {
                    bouqet++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bouqet>=m;
    }
    int minimumDaysToBouqet(int n , vector<int> &nums, int k, int m)
    {
        for(int i=1;i<=maximum(nums);i++){
            if(countBouqet(n,nums,i,k,m)){
                return i;

            }
            
        }
        return -1;
    }
};

int main()
{   int n=4;
    vector<int> nums = {7, 5, 3, 11};
    int k=3;
    int m=2;

    Solution sol;
    int ans = sol.minimumDaysToBouqet(n,nums, k,m);
    cout << ans << endl;
}