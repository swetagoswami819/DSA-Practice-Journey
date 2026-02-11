#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
    string reverseWords(string s){
        int n = s.size();
        int i = n-1;
        string result = "";
        while (i>=0)
        {  
            //skip spaces 
            while (i>=0 && s[i]==' '){
                i--;
            }

            //if out of bounds , break
            if(i<0) break;


            int end = i;
            while (i>=0 && s[i]!=' ')
            {
                i--;
            }

            string word = s.substr(i+1, end-i);

            if(!result.empty()){
                result += " ";
            }

            result += word;
        }
        return result;
    }
};

int main(){
    string s = " amazing coding skills";
    Solution sol;
    cout<<sol.reverseWords(s);
    return 0;
}