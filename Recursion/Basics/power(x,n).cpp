#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    double power(double x, int n){
        double ans=1.0;

        long long nn=n;  //because n can be negative and after multiplying by -1 it out of range (for max range of negative int)
        if(nn<0){
            nn=-1*nn;
        }

        while(nn){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }

        if(n<0){
            ans=double(1.0)/double(ans);
        }
        return ans;

    }

};

int main(){
    double x=2.000;
    int n=10;
    Solution sol;
    sol.power(x,n);
    return 0;
}