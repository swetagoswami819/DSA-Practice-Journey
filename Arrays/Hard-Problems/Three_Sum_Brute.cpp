#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int>&arr){
    
    set<vector<int>>st;
    int n =arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1; k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }

    }

    vector<vector<int>>ans(st.begin(), st.end());

}
int main(){
    vector<int>arr = {-1, 0, 1 ,2 ,-1 ,-4};
    three_sum(arr);
}