#include<bits/stdc++.h>
using namespace std;

void merge(int left , int mid , int right , vector<int>&nums){
    int cnt=0;
    int low = left;
    int high = mid+1;
    vector<int>temp;

    //merging two sorted arrays
    while(low<=mid && high<=right){
        if(nums[low]<=nums[high]){
            temp.push_back(nums[low]);
            low++;
        }
        else{
            temp.push_back(nums[high]);
            high++;
        }

    }

    //remaining left half 
    while(low<=mid){
        temp.push_back(nums[low]);
        low++;
    }

    //remianing right half
    while(high<=right){
        temp.push_back(nums[high]);
        high++;
    }

    //copying back to original array
    for(int i=left;i<=right;i++){
        nums[i]= temp[i-left];
    }
   

}

int count(int left , int mid , int right , vector<int>&nums){
    int cnt=0;
    int high = mid+1;
    for(int i=left;i<=mid;i++){
        while(high<=right && nums[i] > 2LL*nums[high]){
            high++;
        }
        cnt += (high - (mid + 1));
    }
    return cnt;
}
int mergeSort(int left  , int right  , vector<int>&nums){
    if(left>=right) return 0;
    int n = nums.size();
    int cnt=0;
    
    int mid  = (left+right)/2;
    cnt += mergeSort(left , mid , nums);
    cnt += mergeSort(mid+1 , right , nums);
    cnt+= count(left, mid , right, nums);
    merge(left ,  mid , right , nums);
    return cnt;

}

int ReversePairs(vector<int> &nums){
    int n = nums.size();
    return mergeSort(0 , n-1 , nums);
}

int main()
{
    vector<int> arr = {3,2,5,6};
    cout<<ReversePairs(arr);
    return 0;
}

