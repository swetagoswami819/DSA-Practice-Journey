#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void combination(int cnt , string str,vector<string>&ans , vector<string>list){
    
    if(list.size()==str.length()){
        ans.push_back(str);

    }
    
    if(cnt<list.size()){
    for(int i=0;i<list[cnt].length();i++)
    {
        
       string s=list[cnt];
        str+=s[i];
       combination(cnt+1,str,ans,list);
       s=list[cnt];
       str.pop_back();
    
    }
    }
}
    vector<string> letterCombinations(string digits) {
        //your code goes here
        vector<string>list;
        vector<string>ans;

        if(digits.length()==0){
            return ans;
        }

    unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
    
};

for(int i=0;i<digits.length();i++){
    if(mp.find(digits[i])!=mp.end()){
        list.push_back(mp[digits[i]]);
    }
}
combination(0,"",ans,list);
return ans;

    }
};

int main(){
    string digits="123";
    Solution sol;
    vector<string> ans=sol.letterCombinations(digits);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;

}