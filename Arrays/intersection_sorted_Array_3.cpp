//3) - Two Pointer Approach-->
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersection_sorted_array_3(int n1,int n2, vector<int>arr1, vector<int>arr2){

    vector<int>inter;

    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            if(inter.size()==0 || inter.back()!=arr1[i]){
                inter.push_back(arr1[i]);
            }
            i++;
            j++;    
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
      
    return inter;

    }

int main(){

    vector<int>arr1;
    vector<int>arr2;
    
    int n1,n2,x;
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

    vector<int>inter=intersection_sorted_array_3(n1,n2,arr1,arr2);

    for(auto it:inter){
        cout<<it<<" ";
    }

     
    
    return 0;

} 