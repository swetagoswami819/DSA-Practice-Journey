#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int>st;
    stack<int>mn;
    int minVal=INT_MAX;
    public:
        void push(int x){
            st.push(x);
            if(x<=minVal){
                mn.push(minVal);
                minVal=x;
            }

        }

        void pop(){
            if(st.top()==minVal){
                minVal=mn.top();
                mn.pop();
            }
            st.pop();
        }

        int top(){
            return st.top();
        }

        int getmin(){
            return minVal;
        }
};
int main(){
    
      MinStack mn;
    mn.push(5);
    mn.push(8);
    mn.push(-2);
    mn.push(0);
    
    mn.pop();
    cout << "Top: " << mn.top() << endl;
    cout << "Min: " << mn.getmin() << endl;
    
    mn.pop();
    cout << "Min after second pop: " << mn.getmin() << endl;

    return 0;


}