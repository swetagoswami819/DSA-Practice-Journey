#include<iostream>
using namespace std;

class I{
    public:
    void print_numbers_reverse(int n){
        //write code here
        if(n<=0){
            return;

        }
        cout<<n<<endl;
        print_numbers_reverse(n-1);
       

      
    
        
    }
};

int main(){
    int n;
    cin>>n;
    I i;
    i.print_numbers_reverse(n);

    return 0;

}