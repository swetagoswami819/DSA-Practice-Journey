#include<bits/stdc++.h>
using namespace std;

class Solution{

    bool dfs(int src, int col ,vector<int>adj[], vector<int>&vis){
        vis[src]=col;

        for(auto it : adj[src]){
            if(vis[it]==-1){
                if(!dfs(it , !col, adj , vis)) return false;
            }
            else{
            
                    if( vis[it]==col){
                        return false;
                    }
                }
        }
        return true;    
    }
    bool bipartite_graph(vector<int>adj[] , int V){
        

        vector<int>vis(V,-1);

        for(int i=0;i<V;i++){
            if(vis[i]==-1){

                if(!dfs(i ,0, adj , vis)) return false;     
            }
        }
        return true;
    }
};

int main(){
      int m ,n;
    cin>>m>>n;
    vector<int>adj[n];
    int u,v;

    for(int i=0;i<m;i++){ 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    if(obj.bipartite_graph( adj , n)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
