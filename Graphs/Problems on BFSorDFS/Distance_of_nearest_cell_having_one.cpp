#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n=grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;


        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>dist(n, vector<int>(m,0));
    

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i, j}, 0});

                    vis[i][j]=1;

                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};


        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            dist[row][col]=steps;
            q.pop();

            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

               if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
{
                       q.push({{nrow,ncol},steps+1});
                       vis[nrow][ncol]=1;
                }
            }
        }
        return dist;
    }
};

int main(){
    Solution sol;
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>ans = sol.nearest(grid);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}