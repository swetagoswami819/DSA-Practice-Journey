// Painter's Partition
// You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

// Each painter paints only contiguous segments of boards.
// No board can be split between painters.
// The goal is to minimize the time to paint all boards.


// Return the minimum time required to paint all boards modulo 10000003.


// Example 1

// Input: A = 2, B = 5, C = [1, 10]

// Output: 50

// Explanation:

// Painter 1 paints board 0 (length = 1), time = 5
// Painter 2 paints board 1 (length = 10), time = 50
// Max time = 50
// Return 50 % 10000003 = 50

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int partition(vector<int>&C , int B , int mid){
        int paintersNeeded = 1;
        int n = C.size();
        int i=0;
        int timeTaken =0;

        while(i<n){
            if(C[i]*B>mid) return INT_MAX;
            if((timeTaken+(C[i]*B))<=mid){
                timeTaken += (C[i]*B);
            }
            else{
                timeTaken = C[i]*B;
                paintersNeeded++;
            }
            i++;
        }

        return paintersNeeded;

    }
    int paint(int A, int B, vector<int>& C) {
        // Your code goes here

       
        int maximum= *max_element(C.begin(),C.end());
        int sum = accumulate(C.begin(),C.end(),0);
        if(A>=C.size()) return (maximum*B);
        int low = maximum*B;
        int high = sum *B;

        while(low<=high){
            int mid = low + (high-low) / 2;
            if(partition(C,B,mid)<=A){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

    }
};