#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    bool helper(int src , vector<int>adj[] , int vis[] , int parent){
        vis[src]=1;

        for(auto it : adj[src]){
            if(!vis[it]){
                if(helper(it , adj , vis , src)) return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};

        for(int i=0;i<V;i++){
        
                if(!vis[i]){
                    if(helper(i, adj , vis ,-1)){
                        return true;
                    }    
            }
        }
        return false;    
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
    if(obj.isCycle(n, adj)){
        cout<<"Cycle Detected"<<endl;
    }
    else{
        cout<<"No Cycle Detected"<<endl;
    }
    return 0;
}