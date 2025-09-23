#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
    int sqrt(int x){
        if(x==0 || x==1) return x;
        for(int i=1;i<=x/2;i++){
            if(i*i==x) return i;
            if(i*i>x) return i-1;
        }
        return -1;
    }
};

int main(){
    int x;
    cin>>x;
    Solution obj;
    cout<<obj.sqrt(x)<<endl;
    return 0;
}