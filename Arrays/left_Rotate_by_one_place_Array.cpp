#include<iostream>
#include<vector>
using namespace std;

void left_rotate_by_one_place(vector<int>arr){
    int n=arr.size();
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];

    }
    arr[n-1]=temp;

    for(int i=0;i<n;i++){
        cout<<arr[i];
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

    left_rotate_by_one_place(arr);
    return 0;

}