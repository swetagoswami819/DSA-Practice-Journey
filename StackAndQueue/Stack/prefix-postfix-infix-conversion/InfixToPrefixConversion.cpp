#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

     int priority(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

   
    string InfixToPrefix(string s){
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        int i=0;
        string ans="";
        stack<char>st;
        

        while(i<s.length()){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];


            }
            else if(s[i]==')'){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                while(!st.empty() && st.top()!=')'){
                    ans+=st.top();
                    st.pop();

                }
                st.pop(); //pop ')'

            }
            else{
                if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
                st.push(s[i]);
            }
            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       
        return ans;
    }
};

int main(){
    string s="(A-B/C)*(A/K-L)";
    Solution obj;
    string ans = obj.InfixToPrefix(s);
    cout<<ans<<endl;
    return 0;

}