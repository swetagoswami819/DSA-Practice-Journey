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
    int findMax(vector<vector<int>>&mat , int n ,int col ){
        int index = -1;
        int maxElement = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxElement){
                maxElement = mat[i][col];
                index = i;
            }
        }
        return index;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n =mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int col = (low+high)/2;
            int row = findMax(mat , n ,col);
            int left = (col-1>=0) ? mat[row][col-1] : -1;
            int right = (col+1<m) ? mat[row][col+1] : -1;
            if(mat[row][col]>left && mat[row][col]>right) return {row,col};
            else if(mat[row][col]<left) high = col-1;
            else low = col+1;
        }
        return{-1,-1};
    }
};

int main(){
    vector<vector<int>>mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    Solution sol;
    vector<int>ans = sol.findPeakGrid(mat);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}