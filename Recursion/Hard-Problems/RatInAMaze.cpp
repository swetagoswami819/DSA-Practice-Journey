// Rat in a Maze

// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).



// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).



// The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.



// Note :

// In a path no cell can be visited more than once.
// If there is no possible path then return empty vector.

// Example 1

// Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]

// Output : [ "DDRDRR" , "DRDDRR" ]

// Explanation : The rat has two different path to reach (3, 3).

// The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).

// The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<vector<int>>& grid,
               vector<vector<bool>>& vis,
               int i, int j,
               string &s,
               vector<string>& ans){

        int r = grid.size();
        int c = grid[0].size();

        // Base case
        if(i == r-1 && j == c-1){
            ans.push_back(s);
            return;
        }

        vis[i][j] = true;

        // Down
        if(i+1<r && !vis[i+1][j] && grid[i+1][j]==1){
            s.push_back('D');
            solve(grid, vis, i+1, j, s, ans);
            s.pop_back();
        }

        // Left
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
            s.push_back('L');
            solve(grid, vis, i, j-1, s, ans);
            s.pop_back();
        }

        // Right
        if(j+1<c && !vis[i][j+1] && grid[i][j+1]==1){
            s.push_back('R');
            solve(grid, vis, i, j+1, s, ans);
            s.pop_back();
        }

        // Up
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
            s.push_back('U');
            solve(grid, vis, i-1, j, s, ans);
            s.pop_back();
        }

        vis[i][j] = false;
    }

    vector<string> ratInMaze(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<string> ans;

        if(grid[0][0]==0 || grid[r-1][c-1]==0)
            return ans;

        vector<vector<bool>> vis(r, vector<bool>(c, false));
        string s = "";

        solve(grid, vis, 0, 0, s, ans);

        sort(ans.begin(), ans.end());   // optional (for GFG)

        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> result = obj.ratInMaze(grid);

    if(result.empty()) {
        cout << "No Path Found\n";
    } else {
        for(auto path : result) {
            cout << path << endl;
        }
    }

    return 0;
}