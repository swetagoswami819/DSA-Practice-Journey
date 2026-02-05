#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        unordered_map<char , int>v;
        v['I'] = 1;
        v['V'] = 5;
        v['X'] = 10;
        v['L'] = 50;
        v['C'] = 100;
        v['D'] = 500;
        v['M'] = 1000;
        for(int i=0;i<n;i++){
           
            if(i+1<n && v[s[i]]<v[s[i+1]]){
                sum = sum - v[s[i]];
            }
            else{
                sum = sum + v[s[i]];
            }    
        }
        return sum;
    }
};


int main(){
    string s = "XLII";
    Solution sol;
    cout<<sol.romanToInt(s);
    return 0;
}