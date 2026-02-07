#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
    int AtmostKDistinctChar(string s , int k){
        int l =0;
        int res = 0;
        int n = s.size();
        unordered_map<char,int>freq;
        for(int r = 0 ;r<n;r++){
            freq[s[r]]++;

            if(freq.size()>k){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l--;
            }

            res += (r-l+1);
        }
        return res;
    }
};

int main(){
    string s = "pqpqs";
    int k =2;
    Solution sol;
    int ans = sol.AtmostKDistinctChar(s,k)-sol.AtmostKDistinctChar(s,k-1);
    return ans;
}