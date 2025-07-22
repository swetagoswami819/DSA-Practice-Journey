#include<bits/stdc++.h>
using namespace std;

string remove_outermost_parantheses(string s){
    int n=s.length();
    int open=0;
    string ans="";

    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(open>0){
                ans+=s[i];
            }
            open++;
        }
        else if(s[i]==')'){
            open--;
            if(open>0){
                ans+=s[i];
            }
        }
    }
    
     
    return ans;
}
int main(){
    string s;
    getline(cin, s);


    string ans=remove_outermost_parantheses(s);
    cout<<ans;
    return 0;

}