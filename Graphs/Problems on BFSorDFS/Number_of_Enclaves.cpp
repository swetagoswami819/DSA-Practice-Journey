#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, int drow[], int dcol[])
{
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, mat, vis, drow, dcol);
        }
    }
}
int No_of_enclaves(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // traverse the first row and the last row
    for (int j = 0; j < m; j++)
    { // here the j refers to the columns

        // first row
        if (vis[0][j] == 0 && mat[0][j] == 1)
        {
            dfs(0, j, mat, vis, drow, dcol);
        }

        // last row
        if (vis[n - 1][j] == 0 && mat[n - 1][j] == 1)
        {
            dfs(n - 1, j, mat, vis, drow, dcol);
        }
    }

    // traverse the first col and last col
    for (int i = 0; i < n; i++)
    { // here i refers to the rows

        // first col
        if (vis[i][0] == 0 && mat[i][0] == 1)
        {
            dfs(i, 0, mat, vis, drow, dcol);
        }

        // last col
        if (vis[i][m - 1] == 0 && mat[i][m - 1] == 1)
        {
            dfs(i, m - 1, mat, vis, drow, dcol);
        }
    }
int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && vis[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

   int ans= No_of_enclaves(mat);
   cout<<ans;
    return 0;

    
}