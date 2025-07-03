#include<bits/stdc++.h>
using namespace std;

int print_subsequences(vector<int> arr, int index,int sum,int k); 
int subsequences(vector<int> arr,int k){
    vector<int>ds;
    int index=0;
    int sum=0;
    int ans=print_subsequences(arr,index,sum,k);
    return ans;
}

int print_subsequences(vector<int>arr,  int index,int sum,int k){
    //base condition-->
    if(index==arr.size()){
        if(sum==k)
           return 1;
        else 
           return 0;
    }

    sum+=arr[index];
    int l=print_subsequences(arr,index+1,sum,k);
    sum-=arr[index];
    int r=print_subsequences(arr,index+1,sum,k);

    return l+r;
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

    int ans=subsequences(arr,k);
    cout<<ans<<endl;
    return 0;

}