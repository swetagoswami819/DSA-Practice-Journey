#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_matrix_90(vector<vector<int>>&mat,int n){
    vector<vector<int>>new_mat;
    int x;
    vector<int>row;
    for(int i=0;i<n;i++){
        row.clear();
        for(int j=3;j>=0;j--){
            x=mat[j][i];
            row.push_back(x);
        
        }
        new_mat.push_back(row);
    }
    

    return new_mat;
}


int main(){
    int x;
    int n;
    cin>>n;
    vector<int>row;
    vector<vector<int>>mat;
    for(int i=0;i<n;i++){
        row.clear();
        for(int j=0;j<n;j++){
            cin>>x;
            row.push_back(x);
        }
        mat.push_back(row);
    }

    vector<vector<int>>ans=rotate_matrix_90(mat,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}