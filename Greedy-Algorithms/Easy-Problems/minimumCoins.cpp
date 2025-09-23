#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int ans=0;
    for(int i=n-1;i>=0;i--){
        while(n>=coins[i]){
            n-=coins[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}