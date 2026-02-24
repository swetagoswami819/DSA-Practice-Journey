// M Coloring Problem

// Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.



// In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.


// Example 1

// Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]

// Output : true

// Explanation : Consider the three colors to be red, green, blue.

// We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.

// In this way we can color graph using 3 colors at most.

// Note : I have used input as adjacency matrix which we can obtain by creating a function 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(vector<vector<int>>& edges, int color[], int m, int n, int node, int col) {
        for (int k = 0; k < n; k++) {
            if (edges[k][node] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>>& edges, int color[], int m, int n, int node) {
        if (node == n) return true;

        for (int i = 1; i <= m; i++) {
            if (isSafe(edges, color, m, n, node, i)) {

                color[node] = i;

                if (solve(edges, color, m, n, node + 1))
                    return true;

                color[node] = 0; // backtrack
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        int color[n];
        memset(color, 0, sizeof(color));

        return solve(edges, color, m, n, 0);
    }
};

int main() {

    int n = 4; // number of vertices
    int m = 3; // number of colors

    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    Solution obj;

    if (obj.graphColoring(graph, m, n))
        cout << "Coloring possible";
    else
        cout << "Coloring not possible";

    return 0;
}