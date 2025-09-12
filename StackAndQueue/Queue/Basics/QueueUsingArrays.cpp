##include <bits/stdc++.h>
using namespace std;

class QueueImplementation {
public:
int size=10;
    int start=-1;
    int end=-1;
    int currsize=0;
    int q[size];

    void push(int x) {
       if(currsize==size){
        cout<<"queue is overflow"<<endl;
       }
       else{
        if(currsize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        q[end]=x;
        currsize+=1;
       }
    }

    void pop() {
       if(currsize==0){
        cout<<"Qeueu is underflow"<<endl;
        
       }
       else{
       int element= q[start];
       if(currsize==1){
        start=-1;
        end=-1;
       }
       else{
        start=(start+1)%size;
       }
       currsize-=1;
    }
      
    }

    int peek() {
        if(currsize==0){
            return -1;
        }
        else{
            return q[start];
        }
    }

    int size() {
        return currsize;
    }
};

int main() {
    QueueImplementation q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(8);
    q.pop();

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue: " << q.size() << endl;

    return 0;
}
