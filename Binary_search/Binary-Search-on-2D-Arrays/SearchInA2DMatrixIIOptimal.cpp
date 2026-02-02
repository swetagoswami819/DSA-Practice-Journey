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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m =matrix[0].size();
        int row = 0;
        int col = m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;   
    }
};

int main(){
    int n = 3;
    int m = 4;
    vector<vector<int>>nums = {{1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22}};
    Solution sol;
    cout<<sol.searchMatrix(nums , 8);
    return 0;
}