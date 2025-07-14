#include<bits/stdc++.h>
using namespace std;

int first_occur(vector<int>&nums, int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }

        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int last_occur(vector<int>&nums, int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]==target){
            ans=mid;
            low=mid+1;
        }

        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

vector<int> occurence(vector<int>& nums, int target) {
        int l= first_occur(nums,target);
        int r= last_occur(nums,target);
        return {l,r};
        
        
}

int main(){
    int n,x,k;
    cin>>n;
    cin>>k;

    vector<int>arr;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);

    }

    vector<int> ans=occurence(arr,k);
    for(auto it:ans){
        cout<<it<<endl;
    }

}


