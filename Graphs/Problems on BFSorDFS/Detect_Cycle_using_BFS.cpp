#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    bool helper(int src , vector<int>adj[] , int vis[]){

        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=1;


        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }

                else if(it!=parent){
                    return true;

                }

            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};

        for(int i=0;i<V;i++){
        
                if(!vis[i]){
                    if(helper(i, adj , vis)){
                        return true;
                    }    
            }
        }
        return false;    
    }
};


int main(){
    Solution sol;
    int V = 5; // no of edges
    vector<int> adj[V];

    int u,v;

    for(int i=0;i<V;i++){ 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(sol.isCycle(V, adj)){
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}