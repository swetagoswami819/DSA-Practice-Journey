// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.



// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.


// Example 1

// Input: nums = [12, 34, 67, 90], m=2

// Output: 113

// Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int allocate(vector<int>&nums, int maxPages){
        int studentCnt=1;
        int pagesSum =nums[0];

        int i=1;
        int n = nums.size();
        while(i<n){
            if(nums[i]+pagesSum<=maxPages){
                pagesSum += nums[i];
            }
            else{
                studentCnt++;
                pagesSum = nums[i];
            }
            i++;

        }
        return studentCnt;

    }
    int findPages(vector<int> &nums, int m)  {

        if(m>nums.size()) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high =  accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high - low) / 2;
            if(allocate(nums,mid)<=m){
                high = mid-1;
            }    
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

int main(){
    vector<int> nums = {12,34,67,90};
    int m = 2;
    Solution sol;
    cout<<sol.findPages(nums,m);
    return 0;
}