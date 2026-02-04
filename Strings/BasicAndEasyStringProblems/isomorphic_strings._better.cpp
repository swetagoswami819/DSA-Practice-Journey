#include<bits/stdc++.h>
using namespace std;

bool isomorphic_strings(string s, string t){
    map<char,char>mp1;
    map<char,char>mp2;
    if(s.length()!=t.length()){
        return false;
    }

    for(int i=0;i<s.size();i++){
        if(mp1.count(s[i])&& mp1[s[i]]!=t[i]){
            return false;

        }
        else{
            mp1[s[i]]=t[i];
        }

        if(mp2.count(t[i])&& mp2[t[i]]!=s[i]){
            return false;
        }
        else{
            mp2[t[i]]=s[i];
        }

        }
        

    
    return true;
}

int main(){
    
    string s;
    string t;

    getline(cin,s);
    getline(cin,t);
    


    bool ans=isomorphic_strings(s,t);
    cout<<ans;
    return 0;

}