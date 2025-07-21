#include<bits/stdc++.h>
using namespace std;

vector<int> spiral_matrix(vector<vector<int>>mat){   
    
    int n=mat.size();
    int m=mat[0].size();

    int left=0, right=m-1;
    int top=0 , bottom =n-1;

    vector<int>ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
        }
        bottom--;

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
    
    /*int last_i;
    int last_j;
    int last_k;
    for(int t=0;t<n/2;t++){
        for(int i=t;i<(n-t);i++){
            cout<<mat[t][i]<<" ";
            last_i=i;
        }
        //cout<<" last i is :"<<last_i;
        for(int j=t+1;j<(n-t);j++){
            cout<<mat[j][last_i]<<" ";
            last_j=j;
        }

        for(int k=(last_j-1);k>=t;k--){
            cout<<mat[last_j][k]<<" ";
            last_k=k;
            
        }

        //cout<<" last k is :"<<last_k<<endl;
        for(int l=(last_j-1);l>t;l--){
            cout<<mat[l][t]<<" ";
        }

    }*/
    
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

    vector<int> ans=spiral_matrix(mat);
    for(int i=0;i<n*n;i++){
        cout<<ans[i]<<" ";
        
    }
    return 0;
}