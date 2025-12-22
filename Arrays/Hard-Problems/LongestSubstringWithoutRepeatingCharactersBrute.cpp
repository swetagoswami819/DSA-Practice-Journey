#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        int l =0;
        map<char,int>mpp;
        int maxi = INT_MIN;
        
        for(int r=0;r<n;r++){
            mpp[s[r]]++;

            if(mpp[s[r]]>1){
                while(s[l]!=s[r]){
                    mpp[s[l]]--;
                    l++;
                }
                l++;
                mpp[s[r]]--;
            }
            maxi = max(maxi , r-l+1);
        }

        return maxi;
                
    }
};


int main(){
    Solution sol;
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}