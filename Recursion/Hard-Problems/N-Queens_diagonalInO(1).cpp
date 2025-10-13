//it will use hasing to check isafe in O(1) 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   
    void helper(int col, vector<string> &board, vector<vector<string>> &ans , vector<int>&leftRow, vector<int>&lowerDiagonal , vector<int>&upperDiagonal , int n)
    {
        if (col == board.size())
        {
            ans.push_back(board);
            return;
        }

       for(int row=0;row<board.size();row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1 + col-row]=1;
            helper(col+1, board, ans , leftRow, lowerDiagonal , upperDiagonal , n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1 + col-row]=0;


        }
       }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<int>leftRow(n,0);
        vector<int>lowerDiagonal(2*n-1 , 0);
        vector<int>upperDiagonal(2*n-1 , 0);
        vector<string> board(n, string(n, '.'));
        helper(0, board, ans , leftRow , lowerDiagonal , upperDiagonal, n);
        return ans;
    }
};

int main(){
    Solution sol;
    sol.solveNQueens(4);
    return 0;
}