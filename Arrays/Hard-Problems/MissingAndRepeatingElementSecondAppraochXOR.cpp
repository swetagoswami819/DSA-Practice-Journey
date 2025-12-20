#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeatingElementXOR(const vector<int>& arr, int n) {
    int xor_all = 0;

    // Step 1: Compute XOR of all elements in the array and numbers from 1 to n
    for(int num : arr){
        xor_all ^= num;
    }
    for(int i = 1;i<=n;i++){
        xor_all ^= i;
    }

    // Step 2: Find a set bit (rightmost set bit)
    int bit_no =0;
    while((xor_all & (1<<bit_no))==0){
        bit_no++;
    }

    // Step 3: Divide elements into two sets and compute XOR for each set
    int zero = 0;
    int one = 0;

    for(int num : arr){
        //if its non - zero
        if(num & (1<<bit_no) !=0){
            one  ^= num;
        }

        //if its zero
        else{
            zero ^= num;
        }
    }

    for(int i =1 ;i<=n;i++){
        //if its non - zero
        if(i & (1<<bit_no) !=0){
            one  ^= i;
        }

        //if its zero
        else{
            zero ^= i;
        }
    }

    // Step 4: Determine which is missing and which is repeating

    int cnt=0;
  

    for(int num : arr){
        if(num == one){
            cnt++;
        }
    }

    if(cnt==2){
        return {zero , one};
    }
    else{
        return {one, zero};
    }
    
    
}


int main(){
    vector<int> arr = {3, 1, 3, 5, 4};
    int n = arr.size();

    pair<int,int> result = missingAndRepeatingElementXOR(arr, n);
    cout << "Missing Element: " << result.first << ", Repeating Element: " << result.second << endl;

    return 0;
}