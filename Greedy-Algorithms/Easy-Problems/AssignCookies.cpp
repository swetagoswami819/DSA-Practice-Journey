#include<bits/stdc++.h>
using namespace std;

int assign_cookies(vector<int>& greed , vector<int>&size){
    int n=greed.size();
    int m=size.size();
    sort(greed.begin(),greed.end());
    sort(size.begin(),size.end());
    int l=0;
    int r=0;
    while(l<m){
        if(r==n) break;
        if(size[l]>=greed[r]){
            r++;
        }
        l++;
    }

    return r;


} 
int main(){
    vector<int>greed={1,2,3};
    vector<int>size={1,1};
    int ans = assign_cookies(greed,size);
    cout<<ans<<endl;
    return 0;
    

}