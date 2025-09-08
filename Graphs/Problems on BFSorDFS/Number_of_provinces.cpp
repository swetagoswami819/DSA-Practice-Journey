#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void Traverse(vector<vector<int>>& adjls, vector<int>& vis, int node) {
        vis[node] = 1;

        for (auto it : adjls[node]) {
            if (!vis[it]) {
                Traverse(adjls, vis, it);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<vector<int>> adjls(size);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(size, 0);
        int cnt = 0;

        for (int i = 0; i < size; i++) {
            if (vis[i] == 0) {
                cnt++;
                Traverse(adjls, vis, i);
            }
        }

        return cnt;
    }
};


int main(){
    int m ,n;
    cin>>m>>n;
    int starting_node;
    vector<int>adj[n+1];
    int u,v;

    for(int i=0;i<m;i++){ 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>starting_node;
    int ans= NumberOfProvinces(adj,n, starting_node);
    cout<<ans<<endl;
    return 0;
}
};