#include<bits/stdc++.h>
using namespace std;

void rotate_matrix_90(vector<vector<int>>&mat,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);

        }
    }

    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }

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

    rotate_matrix_90(mat,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}