#include<bits/stdc++.h>
using namespace std;

string reverse_words(string s){
    int n=s.length();
    string ans="";

    reverse(s.begin(),s.end());

    for(int i=0;i<n;i++){
        string word="";
        while(i<n && s[i]!=32){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        //cout<<"your word is "<<word<<endl;
        if(word.length()>0){
        ans+=" "+word;
        }
    }

    return ans.substr(1);
}
int main(){
    string s;
    getline(cin, s);


    string ans=reverse_words(s);
    cout<<ans;
    return 0;

}