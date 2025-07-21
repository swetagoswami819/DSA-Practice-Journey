#include<bits/stdc++.h>
using namespace std;


void set_matrix_zeroes(vector<vector<int>>&mat, int m, int n){
    int col[m]={0};
    int row[n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(row[i] || col[j]){
                mat[i][j]=0;
            }
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