#include<bits/stdc++.h>
using namespace std;

int three_sum_closest(vector<int>&arr ,int target){

   
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int ans=arr[0]+arr[1]+arr[2];

    for(int i=0;i<n-1;i++){
        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];

            if(abs(target-sum)<abs(target-ans)){
                ans=sum;
            }

            if(sum==target){
                return target;
            }
            else if(sum<target){
                j++;
            }
            else if(sum>target){
                k--;
            }
            else{

            }

        }
        
    }
    return ans;
   

}
int main(){
    vector<int>arr = {-1, 0, 1 ,2 ,-1 ,-4};
    three_sum_closest(arr,1);
}