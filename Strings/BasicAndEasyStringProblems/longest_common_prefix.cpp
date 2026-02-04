#include<bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string> s) {
    string ans = "";
    int m = s.size();
    if(m == 0) return ans;


    auto it = min_element(s.begin(), s.end(), [](const string &a, const string &b){
        return a.length() < b.length();
    });

    string len = *it;
    int n = len.length();

    for(int i = 0; i < n; i++) {
        char current_char = s[0][i];
        for(int j = 1; j < m; j++) {
            if(s[j][i] != current_char) {
                return ans;
            }
        }
        ans += current_char;
    }

    return ans;
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