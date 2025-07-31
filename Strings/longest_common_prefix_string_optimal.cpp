#include<bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string> s) {
    
   int n=s.size();
   sort(s.begin(),s.end());

   string first_str=s[0];
   string last_str=s[n-1];
   string result="";

   for(int i=0;i<first_str.length();i++){
           if(first_str[i]!=last_str[i]){
            break;
           }
           result+=first_str[i];
   }
   return result;
}


int main(){
    int n;
    cin>>n;
     cin.ignore();
    string v;
    vector<string>s;

    for(int i=0;i<n;i++){
        getline(cin, v); 
        s.push_back(v);   
    }
    


    string ans=longest_common_prefix(s);
    cout<<ans;
    return 0;

}