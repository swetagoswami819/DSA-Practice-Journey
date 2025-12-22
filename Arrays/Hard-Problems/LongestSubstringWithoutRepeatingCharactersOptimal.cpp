#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int l =0;
        vector<int>mpp(256,-1); // {char , last_index}
        int len  = 0;

        for(int r=0;r<n;r++){
            if(mpp[s[r]]!=-1){
                l = max(mpp[s[r]]+1 , l);
            }
            mpp[s[r]]=r;
            len = max(len  ,r-l+1);
        }
        return len;
    }
};


int main(){
    Solution sol;
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}