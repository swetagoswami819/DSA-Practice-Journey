#include<bits/stdc++.h>
using namespace std;


void trappingRainWater(int arr[], int n){
    int left[n];
    int right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], arr[i]);
    }

    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], arr[i]);
    }

    int water = 0;
    for(int i=0; i<n; i++){
        water += min(left[i], right[i]) - arr[i];
    }

    cout<<water<<endl;
}
int main(){
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    trappingRainWater(arr, n);
    return 0;

}