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
        int i=0;
        int j=0;
        int m = arr1.size();
        int n = arr2.size();
        vector<int>temp;

        while(i<m && j<n){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }
            else{
                temp.push_back(arr2[j]);
                j++;
            }
        }

        while(i<m){
            temp.push_back(arr1[i]);
            i++;
        }

        while (j<n)
        {
            temp.push_back(arr2[j]);
            j++;
        }

        int total = m + n;
        if(total % 2 == 1){
            return temp[total/2];
        }
        else{
            return (temp[total/2] + temp[total/2 - 1]) / 2.0;
        }
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