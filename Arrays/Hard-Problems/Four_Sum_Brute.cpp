#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int>&arr, int target){

   
    set<vector<int>>st;

    int n =arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int r=k+1 ; r<n;r++){

                    long long sum =arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[r];

                    if(sum==target){
                        vector<int>temp ={arr[i],arr[j],arr[k],arr[r]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }

                }
            }
        }
    }
    
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;

}
int main(){
    vector<int>arr = {-1, 0, 1 ,2 ,-1 ,-4};
    four_sum(arr, 0);
}