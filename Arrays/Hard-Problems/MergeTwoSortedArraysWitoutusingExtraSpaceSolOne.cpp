#include<bits/stdc++.h>
using namespace std;

void generate(vector<int>&nums1 , vector<int>&nums2){
    int n = nums2.size()-1;
    int l = nums1.size()-1;
    int r = 0;

    while(l>=0 && r<n){
        if(nums1[l]>nums2[r]){
            swap(nums1[l], nums2[r]);
            l--;
            r++;
        }
        else{
            break;
        }
    }
}


int main(){
    vector<int>nums1 = {1,3,5,7};
    vector<int>nums2 = {0,2,6,8,9};

    generate(nums1,nums2);
    return 0;
}