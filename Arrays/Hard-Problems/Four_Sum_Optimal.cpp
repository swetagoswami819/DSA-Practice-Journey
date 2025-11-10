#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int>&arr , int target){

    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int n = arr.size();

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
       

        for(int j =i+1;j<n;j++){
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
        
             int k=j+1;
        int r= n-1;
        while(k<r){
            long long sum = arr[i];
            sum+=arr[j];
            sum+=arr[k];
            sum+=arr[r];

            if(sum<target){
                k++;
            }
            else if(sum>target){
                r--;
            }
            else{
                vector<int>temp = {arr[i], arr[j] , arr[k] ,arr[r]};
                ans.push_back(temp);
                k++;
                r--;

                while(k<r && arr[k]==arr[k-1]) k++;
                while(k<r && arr[r]==arr[r+1]) r--;

            }

        }
       
    }
        
    }
    return ans;

}
int main(){
    vector<int>arr = {-1, 0, 1 ,2 ,-1 ,-4};
    four_sum(arr , 0);
}