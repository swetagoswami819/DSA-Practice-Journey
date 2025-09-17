#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void PostfixToPrefix(string s){
        int i=0;
        stack<string>st;

        while(i<s.length()){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z') || (s[i]>='0' && s[i]<='9')){
                string t(1,s[i]);
                st.push(t);

            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string temp=s[i]+t2+t1;
                st.push(temp);

            }
            i++;
        }
        return st.top();
    }

    
};

int main(){
    string s="AB-DE+F*/";
    Solution obj;
    string ans= obj.PostfixToPrefix(s);
    cout<<ans<<endl;
    
    return 0;

}