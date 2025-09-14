#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int>st;
    
    int minVal;
    public:
        void push(int x){

            if(st.empty()){
                st.push(x);
                minVal=x;
            }
            else{
                if(x>minVal) st.push(x);
                else{
                    st.push(2*x-minVal);
                    minVal=x;

                }
            }
        
        }

        void pop(){
            if(st.empty()) return;
            int x=st.top();
            st.pop();
            if(x<minVal){
                minVal=(2*minVal-x);
            }
        }

        int top(){
            if(st.empty()) return -1;
            int x=st.top();
            if(x>minVal) return x;
            return minVal;
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