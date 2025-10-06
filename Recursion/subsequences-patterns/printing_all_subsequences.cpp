#include<bits/stdc++.h>
using namespace std;

void print_subsequences(vector<int> arr, vector<int> ds, int index); 
void subsequences(vector<int> arr){
    vector<int>ds;
    int index=0;
    print_subsequences(arr,ds,index);
}

void print_subsequences(vector<int>arr, vector<int>ds, int index){
    //base condition-->
    if(index==arr.size()){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    ds.push_back(arr[index]);
    print_subsequences(arr,ds,index+1);
    ds.pop_back();
    print_subsequences(arr,ds,index+1);
}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    subsequences(arr);
    return 0;

}