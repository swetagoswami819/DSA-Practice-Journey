#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void right_rotate_by_d_places(vector<int>&arr,int d){
    reverse(arr.begin(),arr.end()-d);
    reverse(arr.end()-d,arr.end());
    reverse(arr.begin(),arr.end());
    
}

int main(){

    vector<int>arr;
    int n,x,d;
    cin>>n;
    cin>>d;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);

    }
     
    right_rotate_by_d_places(arr,d);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;

}