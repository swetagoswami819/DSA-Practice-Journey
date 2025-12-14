#include<bits/stdc++.h>
using namespace std;

void swapNums(vector<int>nums1 , vector<int>nums2 , int l , int r){
    if(nums1[l]>nums2[r]){
        swap(nums1[l], nums2[r]);
    }
}
void merge(vector<int>nums1 , vector<int>nums2){
    int m = nums1.size();
    int n =nums2.size();
    int len = (nums1.size()-1) + (nums2.size()-1);
    int gap = ceil(len/2);

    while(gap>0){
        int left=0;
        int right = left+gap;

        while(right<len){
            //left and right are in different arrays
            if(left<m && right>=n){
                swapNums(nums1, nums2, left , right-n);
            }

            //left and right bothare in nums2
            else if(left>=n){
                swapNums(nums1, nums2, left-n , right-n);
            }
            
            //left and right bothare in nums1
            else{
                swapNums(nums1, nums2, left , right);
            }
            left++;
            right++;
        }

        if(gap==1){
            break;
        }
        gap = ceil(gap/2);
        
    }

}

int main(){
    vector<int>nums1 = {1,3,5,7};
    vector<int>nums2 = {0,2,6,8,9};

    merge(nums1,nums2);
    return 0;
}