#include<bits/stdc++.h>
using namespace std;

/*adjacency matrix--> (for undirected graph)
int main(){
    int m,n;
    //no of nodes
    //m is no of edges
    //for ex: there are m no of edges defined as [2,3] [3,2] [4,1] [1,4] [5,6] [6,5] [7,9][9,7]
    cin>>n>>m;
    int u,v;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }
    return 0;
    
}*/


/*adjacency matrix--> (for directed graph)
int main(){
    int m,n;
    //no of nodes
    //m is no of edges
    //for ex: there are m no of edges defined as [2,3] [3,2] [4,1] [1,4] [5,6] [6,5] [7,9][9,7]
    cin>>n>>m;
    int u,v;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u][v]=1;

    }
    return 0;
    
}*/


/*adjacency List--> (for both graph)*/
int main(){
    int m,n;
    //no of nodes
    //m is no of edges
    //for ex: there are m no of edges defined as [2,3] [3,2] [4,1] [1,4] [5,6] [6,5] [7,9][9,7]
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}




