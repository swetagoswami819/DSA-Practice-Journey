#include <bits/stdc++.h>
using namespace std;

int three_sum_closest(vector<int> &arr, int target)
{
    int ans = arr[0]+arr[1]+arr[2];
    
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    three_sum_closest(arr, 1);
}