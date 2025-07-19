#include<bits/stdc++.h>
using namespace std;


int single_element_brute(vector<int>arr, int n){
    int hash[1001]={0};

    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=0;i<1001;i++){
        if(hash[i]==1){
            return i;
        }
    }

}
int main(){

    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    int ans=single_element_brute(arr,n);
    cout<<ans;
    return 0;
}