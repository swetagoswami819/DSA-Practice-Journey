#include<iostream>
using namespace std;


int largest_element(int arr[], int n){
    int lar=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>lar){
            lar=arr[i];
        }


    }
    return lar;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    

    }
    
    int ans=largest_element(arr,n);
    cout<<"largest element in given array is :"<<ans<<endl;
    return 0;
}