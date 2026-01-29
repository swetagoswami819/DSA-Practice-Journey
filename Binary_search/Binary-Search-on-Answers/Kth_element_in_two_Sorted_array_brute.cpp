// Kth element of 2 sorted arrays

// Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.


// Example 1

// Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5

// Output: 6

// Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

// Example 2

// Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7

// Output: 256

// Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &arr1, vector<int>& arr2, int k) {
      
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

        int cnt = 0;
        for(auto it: temp){
            cnt++;
            if(cnt == k){
                return it;
            }
        }
    return -1; 
  }
};

int main(){
    Solution sol;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << sol.kthElement(a, b, k) << endl; // Output: 6
    return 0;
}