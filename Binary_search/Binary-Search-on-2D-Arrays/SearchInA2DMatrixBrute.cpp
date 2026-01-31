// Search in a 2D matrix

// Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, and the first element of a row is greater than the last element of the previous row (if it exists), and an integer target, determine if the target exists in the given mat or not.


// Example 1

// Input: mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8

// Output: True

// Explanation: The target = 8 exists in the 'mat' at index (1, 3).

// Example 2

// Input: mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78

// Output: False

// Explanation: The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 
    bool binarySearch(vector<vector<int>>&nums , int target){
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n = 3;
    int m = 4;
    vector<vector<int>>nums = {{1,2,3,4},{5,6,7,8},{10,11,12,13}};
    Solution sol;
    cout<<sol.binarySearch(nums , 8);
    return 0;
}