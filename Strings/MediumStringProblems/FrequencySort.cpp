// Sort Characters By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ans;
			unordered_map<char , int> mpp;
			for(auto it : s){
				mpp[it]++;

			}

            vector<pair<char , int>>v(mpp.begin(),mpp.end());
			sort(v.begin(),v.end(), [](auto &a ,  auto &b){
				return a.second>b.second;
			});
			
			for(auto &it:v){
                for(int i=0;i<it.second;i++){
                    ans.push_back(it.first);

                }
				
			}
	        return ans;
    }
};


int main(){
    string s = "tree";
    Solution sol;
    cout<<sol.frequencySort(s);
    return 0;
}