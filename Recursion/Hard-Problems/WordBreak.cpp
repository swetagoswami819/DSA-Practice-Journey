// 139. Word Break

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     
    bool solve(string s, vector<string>& wordDict , int start){
        if(start == s.size()){
            return true;
        }
        
        for(int i = start; i < s.size(); i++){
            
            string word = s.substr(start, i - start + 1);
            
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                
                if(solve(s, wordDict, i + 1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict, 0);
    }
};

int main() {
    
    Solution obj;
    
    string s = "catsanddog";
    
    vector<string> wordDict = {"cats", "cat", "and", "sand", "dog"};
    
    if(obj.wordBreak(s, wordDict)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    
    return 0;
}