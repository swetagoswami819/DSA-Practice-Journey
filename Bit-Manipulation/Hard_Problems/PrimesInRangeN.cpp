#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>primes(n+1,1);

        primes[0] = primes[1] = 0;
        //seive of erasthoneses
        for(int i=2;i*i<=n;i++){
            if(primes[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }

        }

    
    for(int i=2;i<=n;i++){
            if(primes[i]==1) cout<<i<<" ";

        }
        return 0;
}