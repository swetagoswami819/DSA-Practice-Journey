/*Sum of Beauty of all substring

Problem Statement: The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.

Given a string s, return the sum of beauty values of all possible substrings of s.

Example:
Input:
 s = "xyx"
Output:
 1
Explanation:
 The substrings with non-zero beauty are:
"xyx" → frequencies: x:2, y:1 → beauty = 2 - 1 = 1
"xy" → x:1, y:1 → beauty = 0
"yx" → y:1, x:1 → beauty = 0
"x" or "y" → beauty = 0
Total sum = 1 (from "xyx") = 1*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n  = s.size();
        int sum =0;
        

        for(int i =0;i<n;i++){
            unordered_map<char , int>freq;
            for(int j =i;j<n;j++){
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it : freq){
                    mini = min(mini , it.second);
                    maxi = max(maxi , it.second);    
                }

                sum = sum + (maxi-mini);

            }
        }
        return sum;
    }
};

int main(){
    string s = "xyz";
    Solution sol;
    cout<<sol.beautySum(s);
    return 0;
}