#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const long long MOD = 1e9+7;
long long  power(long long  x, long long  n){
        long long  ans=1;
        x=x%MOD;

        
        while(n>0){
            if(n%2!=0){
                ans=(ans*x)%MOD;
                n=n-1;
            }
            else{
                x=(x*x)%MOD;
                n=n/2;
            }
        }

      
        return ans;

    }
    int countGoodNumbers(long long n) {
        // Your code goes here
        long long odd=n/2;
        long long even=(n+1)/2;

        long long ans = (power(4,odd)*power(5,even))%MOD;
        return (int)ans;
        
    }
};


int main(){
    int n=1;
    Solution sol;
    int ans = sol.countGoodNumbers(n);
    cout<<ans<<endl;
    return 0;
}
