#include<bits/stdc++.h>
using namespace std;

void print_subsequences(vector<int> arr, vector<int> ds, int index,int sum,int k); 
void subsequences(vector<int> arr,int k){
    vector<int>ds;
    int index=0;
    int sum=0;
    print_subsequences(arr,ds,index,sum,k);
}

void print_subsequences(vector<int>arr, vector<int>ds, int index,int sum,int k){
    //base condition-->
    if(index==arr.size()){
        if(sum==k){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
        return;
    }

    ds.push_back(arr[index]);
    sum+=arr[index];
    print_subsequences(arr,ds,index+1,sum,k);
    ds.pop_back();
    sum-=arr[index];
    print_subsequences(arr,ds,index+1,sum,k);
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

    subsequences(arr,k);
    return 0;

}