#include<bits/stdc++.h>
using namespace std;

string largest_odd_in_string(string s){
    int n=s.length();
    int sum=0;
    for(int i=n-1;i>=0;i--){
        int num=s[i]-'0';
        if(num%2==1){
            return s;
        }
        else{
            s.pop_back();
        }
         
    }
    return s;     
}
int main(){
    string s;
    getline(cin, s);


    string ans=largest_odd_in_string(s);
    cout<<ans;
    return 0;

}