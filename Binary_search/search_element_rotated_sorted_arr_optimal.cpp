#include<bits/stdc++.h>
using namespace std;

int search_rotated_1_optimal(vector<int>arr, int n, int target){
    int low=0;
    int high=n-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        
        if(arr[mid]==target){
            return mid;
        }

        else if(arr[low]<=arr[mid]){
            if(arr[low]<=target && arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        else{
            if(arr[mid]<target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
     


}
int main(){
    int n,x,target;
    cin>>n;
    cin>>target;

    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
        int index=search_rotated_1_optimal(arr,n,target);
        cout<<index;

}
