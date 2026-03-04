#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool validSegment(string segment){
        if(segment.size() > 1 && segment[0] == '0')
            return false;

        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }

    void solve(int index, string &s, string sub, int parts, vector<string> &ans){
        
        if(parts == 4 && index == s.size()){
            ans.push_back(sub);
            return;
        }

        if(parts == 4 || index == s.size())
            return;

        for(int len = 1; len <= 3; len++){
            
            if(index + len > s.size())
                break;

            string segment = s.substr(index, len);

            if(validSegment(segment)){
                string newSub = sub.empty() ? segment : sub + "." + segment;
                solve(index + len, s, newSub, parts + 1, ans);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        if(s.size() < 4 || s.size() > 12)
            return ans;

        solve(0, s, "", 0, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    vector<string> result = obj.restoreIpAddresses(s);

    cout << "Valid IP Addresses:\n";
    for(auto ip : result){
        cout << ip << endl;
    }

    return 0;
}