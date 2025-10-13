#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void helper(int ind , string s , vector<string>&ds, vector<vector<string>>&ans){
    if(ind==s.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            ds.push_back(s.substr(ind , i-ind+1));
            helper(i+1, s , ds,ans);
            ds.pop_back();

        }
        
    }

}

bool isPalindrome(string s , int start , int end){
    if(start==end){
        return true;
    }
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
    vector<vector<string>> partition(string s) {
        //your code goes here
        vector<string>ds;
        vector<vector<string>>ans;
        helper(0,s,ds,ans);
        return ans;
    }
};

int main(){
    Solution sol;
    string s= "aabb";
    sol.partition(s);
    return 0;
}