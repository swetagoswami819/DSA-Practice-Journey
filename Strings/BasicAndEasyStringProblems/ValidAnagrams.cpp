// Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.


// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int>count(26,0);
        for(auto it : s){
            count[it - 'a']++;
        }

        for(auto it : t){
            count[it - 'a']--;
        }
        

        for(auto it : count){
            if(it!=0){
                return false;
            }
        }
        return true;
    }
};

int main(){

    string s = "cat";
    string t = "bat";
    Solution sol;
    cout<<sol.isAnagram(s,t);
    return 0;
}
