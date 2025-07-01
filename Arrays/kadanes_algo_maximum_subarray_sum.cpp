#include<bits/stdc++.h>
using namespace std;

int maximum_subarray_kadanesalgo(vector<int>arr, int n){
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        
        if(sum>maxi){
            maxi=max(sum,maxi);     
        }
        if(sum<0){
            sum=0;
        }
    }

    return maxi;

}
int main(){
    int n,x;
    vector<int>arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int ans=maximum_subarray_kadanesalgo(arr,n);

    cout<<ans;
    return 0;
}