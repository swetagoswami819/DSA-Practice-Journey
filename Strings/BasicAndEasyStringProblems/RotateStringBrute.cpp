#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
	    bool patternMatcher(string & s , string & goal , int start , int end){
			int m = s.size();
			int cnt  = 0;
			while (cnt < goal.size()) {
                if (s[start] != goal[cnt]) {
                    return false;
                }
            cnt++;
            start = (start + 1) % m;
            }
			return true;
		}
		bool rotateString(string& s,string& goal){
			//your code goes here
			int n = s.size();
			int m = goal.size();
			if(m!=n) return false;
			for(int i =0;i<n;i++){
				if(patternMatcher(s, goal , i ,m+i-1)){
					return true;
				}
			}
			return false;
		}
};


int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution sol;
    cout<<sol.rotateString(s,goal);
    return 0;
}