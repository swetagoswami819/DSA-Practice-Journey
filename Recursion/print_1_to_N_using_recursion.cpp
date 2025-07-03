#include<iostream>
using namespace std;

class H{
    public:
    void print_numbers(int n){
        //write code here
        if(n<=0){
            return;

        }
        print_numbers(n-1);
        cout<<n<<endl;

      
    
        
    }
};

int main(){
    int n;
    cin>>n;
    H h;
    h.print_numbers(n);

    return 0;

}