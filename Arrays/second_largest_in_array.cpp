#include<iostream>
#include<algorithm>
using namespace std;


int slargest(int arr[], int n){
    int lar=arr[0],slar=-1;
   
    for(int i=0;i<n;i++){
        if(arr[i]>lar){
            slar=lar;
            lar=arr[i];     
        }
        else if(arr[i]<lar && arr[i]>slar){
             slar=arr[i];     
     }
    }
    return slar;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans=slargest(arr,n);
    cout<<ans;

}