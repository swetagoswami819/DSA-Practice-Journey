#include<bits/stdc++.h>
using namespace std;

int single_element_arr_better(vector<int>arr, int n){
    if(arr.size()==1){
        return arr[0];
    }
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    

    for(int i=0;i<n;i++){
    if(arr[i]!=arr[i+1]){
        return arr[i];
    }
    i++;
    }
return -1;
}

int main(){
    int n,x;
    cin>>n;
    

    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
        int  index=single_element_arr_better(arr,n);
        cout<<index;

}
