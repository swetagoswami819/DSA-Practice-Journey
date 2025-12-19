#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        long long sumOfN = 1LL * n * (n + 1) / 2;
        long long sumOfNSqaure = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long  sum = 0;
        long long  sumSquare = 0;

        for(auto it : nums){
            sum += it;
            sumSquare += 1LL * it * it;
        }

        long long  val1 = sum - sumOfN;
        long long  val2 = sumSquare - sumOfNSqaure;
        val2 = val2/val1;
        long long x  = (val1 + val2) /2;
        long long y  = x - val1;
        

        return {(int)x,(int)y};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,2,4};
    vector<int> result = sol.findErrorNums(nums);
    cout << "Missing and Repeating elements are: ";
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}