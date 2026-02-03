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
    int median(vector<vector<int>>&mat , int n , int m){
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int cnt = temp.size()/2;
        return temp[cnt];
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