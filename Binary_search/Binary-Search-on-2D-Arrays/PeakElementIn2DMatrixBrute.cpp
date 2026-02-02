// Find Peak Element - II

// Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j].A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.



// Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.



// Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.


// Example 1

// Input: mat=[[10, 20, 15], [21, 30, 14], [7, 16, 32]]

// Output: [1, 1]

// Explanation: The value at index [1, 1] is 30, which is a peak element because all its neighbours are smaller or equal to it. Similarly, {2, 2} can also be picked as a peak.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        int maxElement = -1;
        int row =-1 , col =-1;
        for(int i=0;i<n;i++){
            for(int  j =0;j<m;j++){
                if(mat[i][j]>maxElement){
                    maxElement = mat[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        return {row,col};
    }
};

int main(){
    vector<vector<int>>mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    Solution sol;
    vector<int>ans = sol.findPeakGrid(mat);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}