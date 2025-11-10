#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> &arr, int target)
{

    set<vector<long long>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;

            for (int k = j + 1; k < n; k++)
            {

                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                long long fourth = target - (sum);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<long long> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    four_sum(arr, 0);
}