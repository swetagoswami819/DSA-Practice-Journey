#include<bits/stdc++.h>
using namespace std;

class Solution{
private :
void Traverse(vector<int>adj[], int node , int vis[], vector<int>ls){
    vis[node]=1;
    ls.push_back(node);
    //traverse all its neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            Traverse(adj,it,vis,ls);
        }
    }
}
public :
vector<int> DFS_Traversal(vector<int>adj[], int n, int starting_node){
    int vis[n+1]={0};
    vector<int>ls;
    Traverse(adj,starting_node,vis,ls);
    return ls;
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
    vector<int> ans=DFS_Traversal(adj,n, starting_node);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}
};