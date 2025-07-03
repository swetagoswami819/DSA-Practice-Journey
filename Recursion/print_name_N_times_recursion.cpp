#include<iostream>
using namespace std;

class G{
    public:
    void print_name(string x , int n){
        //write code here
        if(n<=0){
            return;

        }
        cout<<x<<endl;
        print_name(x,n-1);
    
        
    }
};

int main(){
    int n;
    string S;
    cin>>n>>S;
    G g;
    g.print_name(S,n);
    return 0;

}