#include<bits/stdc++.h>
using namespace std;
 
vector<int> Two_sum_problem_2_pointer(vector<int> arr, int target){

    vector<pair<int ,int>>vec;
    int n=arr.size();
    int sum;
    int left=0,right=n-1;
    for(int i=0;i<n;i++){
        vec.push_back({arr[i],i});
    }
    sort(vec.begin(),vec.end());
    while(left<right){
        sum=vec[left].first+vec[right].first;
        if(sum==target){
            return{vec[left].second,vec[right].second};
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }

        
    }
     

}

int main(){

    vector<int>arr;
    int n,x,k;
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    vector<int> res= Two_sum_problem_2_pointer(arr,k);
    cout<<res[0]<<" "<<res[1];
    
    return 0;

}