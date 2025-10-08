#include<bits/stdc++.h>
using namespace std;

void subsequence(int k , int n ,vector<int>&ds,vector<vector<int>>&ans, int index);

void sum(int k, int n){
    vector<int>ds;
    vector<vector<int>>ans;
    int index=1;
    subsequence(k,n,ds,ans,index);

    for(auto it:ans){
        for(auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

void subsequence(int k , int n,vector<int>&ds,vector<vector<int>>&ans, int index){   //Base condition-->
    if(n==0 && ds.size()==k){
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<=9;i++){
        
      if(i<=n){


        ds.push_back(i);

        subsequence(k,n-i,ds,ans,i+1);
        ds.pop_back();
      }
    }


}
int main(){
    int n,k;
    cin>>n;
    cin>>k;

    sum(k,n);
    return 0;
}