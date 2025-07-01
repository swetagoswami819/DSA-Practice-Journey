#include<bits/stdc++.h>
using namespace std;

vector<int> union_sorted_arr(int n1,int n2, vector<int>arr1, vector<int>arr2){

    vector<int>arr;
    int i=0,j=0;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(arr.size()==0 ||  arr.back()!=arr1[i]){
                arr.push_back(arr1[i]);
            }
            i++;

        }

        else{
            if(arr.size()==0 || arr.back()!=arr2[j]){
                arr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1){
         if(arr.size()==0 ||  arr.back()!=arr1[i]){
                arr.push_back(arr1[i]);
        }
            i++;

    }

    while(j<n2){
         if(arr.size()==0 || arr.back()!=arr2[j]){
                arr.push_back(arr2[j]);
            }
            j++;

    }

    return arr;

}

int main(){
    int n1,n2,x;
    vector<int>arr1;
    vector<int>arr2;

    cin>>n1;
    cin>>n2;

    for(int i=0;i<n1;i++){
        cin>>x;
        arr1.push_back(x);

    }

    for(int i=0;i<n2;i++){
        cin>>x;
        arr2.push_back(x);

    }

    vector<int>arr=union_sorted_arr(n1,n2,arr1,arr2);

    for(auto it:arr){
        cout<<it;
    }

}