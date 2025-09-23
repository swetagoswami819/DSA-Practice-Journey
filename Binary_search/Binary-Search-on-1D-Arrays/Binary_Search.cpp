#include<bits/stdc++.h>
using namespace std;
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
        
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

    int ans=search(arr,k);
    cout<<ans<<endl;

}



