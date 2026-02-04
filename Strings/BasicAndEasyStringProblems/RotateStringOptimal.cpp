#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
	    
		bool rotateString(string& s,string& goal){
			//your code goes here
			int n = s.size();
			int m = goal.size();
			return (m==n && (s+s).find(goal)!=string::npos);
		}
};


int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution sol;
    cout<<sol.rotateString(s,goal);
    return 0;
}