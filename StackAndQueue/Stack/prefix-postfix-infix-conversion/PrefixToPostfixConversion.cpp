#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void PrefixToPostfix(string s){
        int i=s.length()-1;
        stack<string>st;

        while(i>=0){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z') || (s[i]>='0' && s[i]<='9')){
                string t(1,s[i]);
                st.push(t);

            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string temp=t1+t2+s[i];
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
    string ans= obj.PrefixToPostfix(s);
    cout<<ans<<endl;
    
    return 0;

}