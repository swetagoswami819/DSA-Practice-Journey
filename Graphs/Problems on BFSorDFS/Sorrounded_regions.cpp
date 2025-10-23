#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis, int drow[], int dcol[])
{
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, mat, vis, drow, dcol);
        }
    }
}
void sorrounding_regions(vector<vector<char>> &mat)
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
        if (vis[0][j] == 0 && mat[0][j] == 'O')
        {
            dfs(0, j, mat, vis, drow, dcol);
        }

        // last row
        if (vis[n - 1][j] == 0 && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, mat, vis, drow, dcol);
        }
    }

    // traverse the first col and last col
    for (int i = 0; i < n; i++)
    { // here i refers to the rows

        // first col
        if (vis[i][0] == 0 && mat[i][0] == 'O')
        {
            dfs(i, 0, mat, vis, drow, dcol);
        }

        // last col
        if (vis[i][m - 1] == 0 && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, mat, vis, drow, dcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O' && vis[i][j] == 0)
            {
                mat[i][j] = 'X';
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    sorrounding_regions(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
    }
}