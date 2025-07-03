#include<bits/stdc++.h>
using namespace std;

vector<int> permutation_3(vector<int>arr){
    int index;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }

    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    
    else{
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>arr[index]){
                swap(arr[index],arr[i]);
                break;
            }
        }
        reverse(arr.begin()+index+1,arr.end());
        return arr;
    }
}
int main(){
    vector<int>arr;
    int n,x;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    vector<int> ans=permutation_3(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }


}