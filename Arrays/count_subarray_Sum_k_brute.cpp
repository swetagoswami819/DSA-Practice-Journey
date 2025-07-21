#include<bits/stdc++.h>
using namespace std;

int count_subarrays_sum_k(vector<int>arr, int n,int k){
     int count=0;
     int sum;
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];

            }
            if(sum==k){
                count++;
            }

        }
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