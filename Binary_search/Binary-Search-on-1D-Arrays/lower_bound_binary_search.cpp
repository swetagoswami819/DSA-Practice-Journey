#include<bits/stdc++.h>
using namespace std;
    int lower_bound(vector<int>& nums, int target) {
        int low=0;
        int ans=nums.size()-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }

        return ans;
        
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

    int ans=lower_bound(arr,k);
    cout<<ans<<endl;

}



