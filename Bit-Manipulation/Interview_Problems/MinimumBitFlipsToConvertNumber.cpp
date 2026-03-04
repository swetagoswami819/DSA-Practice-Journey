#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = (start^goal);
        int cnt = 0;
        while(num){
            num = num & (num-1);
            cnt++;
        }
        return cnt;
    }
};

int main(){
    int start = 3;
    int goal = 4;
    Solution sol;
    cout<<sol.minBitFlips(start,goal);
    return 0;
}