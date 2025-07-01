#include<bits/stdc++.h>
using namespace std;
 
void Dutch_Algo_sort_arr_0_1_2_brute(vector<int>&arr)
{
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
            
        }
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

    Dutch_Algo_sort_arr_0_1_2_brute(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;

}