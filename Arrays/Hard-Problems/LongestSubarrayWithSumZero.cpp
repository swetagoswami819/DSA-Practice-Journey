#include <bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> nums)
{
    map<int, int> prefixSum;
    int sum = 0;
    int maxLength = 0;
    prefixSum[0] = -1; // To handle the case when subarray starts from index 0

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            maxLength = i + 1;
        }
        else
        {
            if (prefixSum.find(sum) != prefixSum.end())
            {
                maxLength = max(maxLength, i - prefixSum[sum]);
            }
            else
            {
                prefixSum[sum] = i;
            }
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {1, -1, 3, 2, -2, -3, 3};
    cout << findSubarray(nums);
    return 0;
}