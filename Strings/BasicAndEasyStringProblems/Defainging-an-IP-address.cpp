#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for(char c : address) {
            if(c == '.') 
                result += "[.]";
            else 
                result += c;
        }
        return result;
    }
};

int main() {
    Solution sol;

    string ip = "1.1.1.1"

    string defanged = sol.defangIPaddr(ip);
    cout<<defanged<<endl;

    return 0;
}
