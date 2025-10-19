#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
          int n = image.size();
        int m = image[0].size();

        if (image[sr][sc] == newColor) return image;


        queue<pair<int,int>>q;

        q.push({sr,sc});
        int value =  image[sr][sc];
        image[sr][sc]=newColor;
        

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = { 0 , 1 , 0 , -1};

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==value){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=newColor;
                }
            }
        }

        return image;
        
    }
};

int main(){
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    for (const auto& row : result) {
        for (const auto& col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}

