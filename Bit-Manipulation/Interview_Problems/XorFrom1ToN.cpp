#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findXOR(int n){
        
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else if(n%4==0) return n;
        else return 0;

    }
     
};

int main(){
    int n = 3;
    Solution sol;
    cout<<sol.findXOR(n);
    return 0;
}