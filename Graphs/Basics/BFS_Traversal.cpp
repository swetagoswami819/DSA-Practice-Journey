#include<bits/stdc++.h>
using namespace std;


void BFS_Traversal(vector<int>adj[], int n, int starting_node){
    queue<int>q;
    int vis[n+1]={0};

    vis[starting_node]=1;
    q.push(starting_node);

    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        
        for(auto it : adj[top]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
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
    BFS_Traversal(adj,n, starting_node);
    return 0;
}