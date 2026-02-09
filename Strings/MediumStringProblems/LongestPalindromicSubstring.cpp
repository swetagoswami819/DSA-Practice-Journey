#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 
    string longestpalindromicsubstring(string s){
        if(s.size()==0 && s.size()<=1) return s; 
    int start =0;
    int end = 0;
    for(int i=0;i<s.size();i++){
        int len1 = expandFromMiddle(s,i,i);
        int len2 = expandFromMiddle(s, i ,i+1);
        int len = max(len1, len2);
        if(len > end-start){
            start = i - ((len-1)/2);
            end = i + (len/2);
        }
    }
    return s.substr(start ,end-start+1);

    }

    int expandFromMiddle(const string &s , int left , int right){
        if(s.size()==0 || left>right) return 0;
        while (left >=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    
};

int main(){
    string s =  "abbacd";
    Solution sol;
    cout<<sol.longestpalindromicsubstring(s);
    return 0;
}