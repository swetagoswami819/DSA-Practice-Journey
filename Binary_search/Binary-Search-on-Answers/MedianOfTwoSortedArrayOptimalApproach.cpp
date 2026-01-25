// Median of 2 sorted arrays

// Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

// The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.


// Example 1

// Input: arr1 = [2, 4, 6], arr2 = [1, 3, 5]

// Output: 3.5

// Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 5, 6 ]. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double median(vector<int>&arr1, vector<int>&arr2){
        int low =0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int high = min(n1,n2);
        int elements = (n1+n2+1)/2;

        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = elements-mid1;

            int l1  = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MIN , r2 = INT_MIN;

            if(mid1<n1) r1 = arr1[mid1];
            if(mid2<n2) r2 = arr2[mid2];
            
            if(mid1-1 >= 0) l1 = arr1[mid1-1];
            if(mid2-1 >= 0) l2 = arr2[mid2-1];


            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else{
                low= mid1+1;
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int>arr1 = {1, 3};
    vector<int>arr2 = {2};
    cout << "Median is: " << sol.median(arr1, arr2) << endl;

    vector<int>arr3 = {1, 2};
    vector<int>arr4 = {3, 4};
    cout << "Median is: " << sol.median(arr3, arr4) << endl;

    return 0;
}