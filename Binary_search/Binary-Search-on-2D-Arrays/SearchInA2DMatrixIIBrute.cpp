// Search in 2D matrix - II

// Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.


// Example 1

// Input: matrix = [ [1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30] ], target = 5

// Output: True

// Explanation: The target 5 exists in the matrix in the index (1,1)


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