#include<bits/stdc++.h>
using namespace std;

void set_matrix_zeroes(vector<vector<int>>&mat, int m, int n){
    //int col[n]={0} -> matrix[0][...]
    //int row[m]={0} -> matrix[...][0];
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                //mark the i-th row
                mat[i][0]=0;  
                if(j!=0){
                //mark the j-th col
                mat[0][j]=0;
                }
                else{
                    col0=0;
                }

            }

        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]!=0){
              if(mat[0][j]==0 || mat[i][0]==0){
                mat[i][j]=0;
              }
            }

        }
    }


    if(mat[0][0]==0){
        for(int j=0;j<m;j++){
            mat[0][j]=0;
        }
    }

    if(col0==0){
        for(int i=0;i<n;i++){
            mat[i][0]=0;
        }
    }

    
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

    set_matrix_zeroes(mat,m,n);

    for(int i=0;i<m;i++){
        row.clear();
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}