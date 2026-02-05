#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign =1;
        long long  sum =0;
        int i=0;
        
        while(i<n && s[i]==' ') i++;

        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = -1;
            i++;
        }

        while(i<n && (s[i]>='0' && s[i]<='9')){
            sum = sum*10 + (s[i]-'0');

            if(sum*sign>INT_MAX) return INT_MAX;
            if(sum*sign<INT_MIN) return INT_MIN;
            i++;
        }


        return sum*sign;
    }
};

int main(){
    string s = "    -4300abc";
    Solution sol;
    cout<<sol.myAtoi(s);
    return 0;
}