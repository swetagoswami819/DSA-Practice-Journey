#include<bits/stdc++.h>
using namespace std;


class Solution{
    public : 


    void generateParantheses(int n, int BalanceCounter, int OpeningParantheses, string str, vector<string>&ds){
        
        //Base condition
        if(OpeningParantheses==n && BalanceCounter ==0){
            ds.push_back(str);
            return;
        }

        if(OpeningParantheses>n || BalanceCounter<0){
            return;
        }
        str+='(';
        generateParantheses(n,BalanceCounter+1,OpeningParantheses+1,str, ds);
        str.pop_back();
        str+=')';
        generateParantheses(n,BalanceCounter-1, OpeningParantheses, str,ds);
        return;
    }

};
int main(){
    int n =3;
    int BalanceCounter=0;
    int OpeningParantheses=0;
    vector<string>ds;
    string str="";
    Solution sol;
    sol.generateParantheses(n, BalanceCounter, OpeningParantheses, str, ds);
    for(auto it : ds){
        cout<<it<<endl;
    }
    return 0;
}