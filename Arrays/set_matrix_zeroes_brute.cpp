#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>&mat,int i,int n){
    for(int j=0;j<n;j++){
        if(mat[i][j]!=0){
            mat[i][j]=-1;
        }
    }
}

void markCol(vector<vector<int>>&mat, int j, int m){
    for(int i=0;i<m;i++){
        if(mat[i][j]!=0){
            mat[i][j]=-1;
        }
    }
}


vector<vector<int>> set_matrix_zeroes(vector<vector<int>>&mat, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                markRow(mat,i,n);
                markCol(mat,j,m);
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1){
                mat[i][j]=0;
            }
        }
    }

    return mat;
}


int main(){
    int m,x;
    int n;
    cin>>m;
    cin>>n;
    vector<int>row;
    vector<vector<int>>mat;
    for(int i=0;i<m;i++){
        row.clear();
        for(int j=0;j<n;j++){
            cin>>x;
            row.push_back(x);
        }
        mat.push_back(row);
    }

    vector<vector<int>>ans=set_matrix_zeroes(mat,m,n);

    for(int i=0;i<m;i++){
        row.clear();
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}