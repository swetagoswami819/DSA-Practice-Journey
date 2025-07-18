#include<bits/stdc++.h>
using namespace std;

int search_rotated_1_optimal(vector<int>arr, int n){
    int low=0;
    int high=n-1;
    int mid;
    int min=INT_MAX;

    while(low<=high){
        mid=(low+high)/2;
        
        if(arr[low]<=arr[high]){
            return arr[low];
        }
        
        if(arr[low]<=arr[mid]){
            if(arr[low]<min){
                min=arr[low];
            }
            low=mid+1;   
        }

        else{
            if(arr[mid]<min){
                min=arr[mid];
            }
            high=mid-1;
        }
    }
    return min;


}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
        int index=search_rotated_1_optimal(arr,n);
        cout<<index;

}
