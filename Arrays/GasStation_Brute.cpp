#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n =gas.size();
        int i;
        int start;
        int flag=1;
        for(i=0;i<n;i++){
            if(gas[i]>cost[i]){
                 start=i;
                int fuel =gas[i];

                for(int j=start;j<2*n;j++){
                    fuel = fuel - cost[j%n] + gas[(j+1)%n];
                    if(fuel<cost[(j+1)%n]){
                        flag=0;
                        break;
                    }
                    
                }
                if(flag==1) return start;
            }

        }

        return -1;
        
    }
};


int main(){

    vector<int>gas={1,2,3,4,5};
    vector<int>cost= {3,4,5,1,2};
    Solution sol;
    int ans= sol.canCompleteCircuit(gas,cost);
    cout<<ans;
}