#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr;
       

        for(int i=0;i<numRows;i++){
            vector<int>row;
            row.push_back(1);
            for(int j=1;j<=i;j++){
                int val = row[j-1]* (i-j+1)/j;
                row.push_back(val);
            }
            arr.push_back(row);
        }
        return arr;
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    vector<vector<int>>ans = sol.generate(n);
    for(auto it : ans){
        for(auto row : it){
            cout<<row<<1<<""; 
        }
        cout<<"\n";
    }
}