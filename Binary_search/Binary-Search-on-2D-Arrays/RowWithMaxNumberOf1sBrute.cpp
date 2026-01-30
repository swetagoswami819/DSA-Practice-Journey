#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int rowIndex(vector<vector<int>> &nums, int n, int m)
    {
        int index = -1;
        int max_cnt = 0;
        int cnt;
        int i, j;

        for (i = 0; i < n; i++)
        {
            cnt = 0;
            for (j = 0; j < m; j++)
            {
                if (cnt += nums[i][j])
                    ;
            }

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