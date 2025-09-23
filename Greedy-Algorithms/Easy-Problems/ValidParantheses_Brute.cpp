#include<bits/stdc++.h>
using namespace std;

class Solution {
bool isValid(string s, int ind , int cnt ){
    if(cnt<0) return false;
    if(ind==s.length()) return (cnt==0);
    if(s[ind]=='(') return isValid(s,ind+1,cnt+1);
    else if(s[ind]==')') return isValid(s,ind+1,cnt-1);
    else return isValid(s,ind+1,cnt+1) || isValid(s,ind+1,cnt-1) || isValid(s,ind+1,cnt);

}
};

int main(){
    Solution obj;
    string s = "(*)";
    cout<<obj.isValid(s,0,0);
    return 0;
}



