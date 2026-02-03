// Matrix Median

// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.


// Example 1

// Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 

// Output: 5

// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    public : 

    int upperBound(vector<int>&mat , int target , int m){
        int low = 0, high = m-1;
        int ans = m;
        while (low<=high)
        {
            int mid = (low+high)/2;
            if(mat[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }  
        }
        return ans;
    }

    int countsmallEqual(vector<vector<int>>&mat,  int mid , int n ,int m){
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += upperBound(mat[i] , mid , m);
        }
        return cnt;
    }
    int median(vector<vector<int>>&mat , int n , int m){
        int low = INT_MAX , high = INT_MIN;
        
        for(int i=0;i<n;i++){
            low = min(low  , mat[i][0]);
            high = max(high , mat[i][m-1]);
        }

        int req = (n*m)/2;
        while(low<=high){
            int mid = (low+high)/2;
            int smallEqual = countsmallEqual(mat , mid ,n , m);
            if(smallEqual>req){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.median(mat, n, m);

    return 0;
}