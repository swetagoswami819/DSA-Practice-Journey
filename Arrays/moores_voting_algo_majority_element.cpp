#include<bits/stdc++.h>
using namespace std;

int  majority_element_loops(vector<int>arr,int n){
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=arr[i];
            cnt=1;
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    
    cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            cnt++;
        }
    }

    if(cnt>(n/2)){
        return el;
    }

    
    
    return -1;
}
int main(){
    int n,x;
    vector<int>arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int ans=majority_element_loops(arr,n);

    cout<<ans;
    return 0;
}