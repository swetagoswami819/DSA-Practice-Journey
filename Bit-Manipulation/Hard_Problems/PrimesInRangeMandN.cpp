#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  void solve(vector<int>&primes , int n){
       primes[0] = primes[1] = 0;
       for(int i=2 ;i*i<=n;i++){
           if(primes[i]==1){
               for(int j=i*i; j<=n;j+=i){
                   primes[j]=0;
               }
               primes[i]=primes[i-1]+1;
           }
           else{
              primes[i]= primes[i-1];
           }
           
       }
       
   }

int main(){
    int M,N;
    cin>>M>>N;
   
      
        int n = max(M,N);
        vector<int>primes(n+1,1);
        solve(primes,n);
        if(M == 0 || M == 1)
            return primes[N];

        return primes[N] - primes[M - 1];
        
    
}
};
