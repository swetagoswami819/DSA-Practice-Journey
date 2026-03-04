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

    int XORInARange(int l ,int r){

        return findXOR(l-1)^findXOR(r);

    }
     
};

int main(){
    int l = 3;
    int r = 5;
    Solution sol;
    cout<<sol.XORInARange(l,r);
    return 0;
}