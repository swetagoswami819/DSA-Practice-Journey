#include<bits/stdc++.h>
using namespace std;

bool isomorphic_strings(string s, string t){
    if (s.length()!=t.length()) 
    {
        return false;
    }

    int mapS[256]={0};  // s -> t
    int mapT[256]={0};  // t -> s

    for (int i=0; i<s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (mapS[c1]==0 && mapT[c2]==0) {
            mapS[c1]=c2;
            mapT[c2]=c1;
        } else {
            if (mapS[c1]!=c2||mapT[c2] != c1)
                return false;
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