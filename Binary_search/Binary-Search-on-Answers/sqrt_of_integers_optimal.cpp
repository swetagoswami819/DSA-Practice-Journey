#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
    int sqrt(int x){
        if(x==0 || x==1) return x;
        int low=1, high=x/2, ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(mid*mid==x) return mid;
            else if(mid*mid<x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    int x;
    cin>>x;
    Solution obj;
    cout<<obj.sqrt(x)<<endl;
    return 0;
}