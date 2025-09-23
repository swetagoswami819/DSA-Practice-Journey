#include<bits/stdc++.h>
using namespace std;

int  no_of_times_rotate(vector<int>arr, int n){
   int low=0;
    int high=n-1;
    int mid;
    int min=INT_MAX;
    int index=0;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==arr[low] && arr[mid]==arr[high]){
            low++;
            high--;
        }
        
        
        if(arr[low]<=arr[high]){
            return low;
        }
        
        if(arr[low]<=arr[mid]){
            if(arr[low]<min){
                min=arr[low];
                index++;
            }
            low=mid+1;   
        }

        else{
            if(arr[mid]<min){
                min=arr[mid];
                index++;
            }
            high=mid-1;
        }
    }
    return index;

}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
        int index=no_of_times_rotate(arr,n);
        cout<<index;

}
