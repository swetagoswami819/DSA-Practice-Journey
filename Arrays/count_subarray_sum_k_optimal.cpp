#include<bits/stdc++.h>
using namespace std;

int count_subarrays_sum_k(vector<int>arr, int n,int k){
    map<int,int>mpp;
    mpp[0]=1;
    int sum=0;
    int count=0;
    int prefixSum;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
         
        prefixSum=sum-k;
        count=count+mpp[prefixSum];
        mpp[sum]++;
    }

    return count;

}
int main(){
    int n,x,k;
    cin>>n;
    cin>>k;
    vector<int>arr;


    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    int ans=count_subarrays_sum_k(arr,n,k);
    cout<<ans<<endl;
}