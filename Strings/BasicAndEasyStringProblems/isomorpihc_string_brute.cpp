#include<bits/stdc++.h>
using namespace std;

bool isomorphic_strings(string s, string t){
    map<char,char>mp;

    if(s.length()!=t.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        char original=s[i];
        char replace=t[i];

        if(!mp.count(original)){
            for(auto it :mp){
                if(it.second == replace){
                    return false;

                }

            }
            mp[original]=replace;
        }
        else{
             if(mp[original]!=replace){
                return false;
             }
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