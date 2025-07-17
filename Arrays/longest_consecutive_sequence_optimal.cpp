#include<bits/stdc++.h>
using namespace std;

int long_consecutive_sequence_optimal(vector<int>&arr, int n){
     int longest=1;
     unordered_set<int>st;

    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;

            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }

    return longest;
}
int main(){
    int n,x;
    cin>>n;

    vector<int>arr;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    int len=long_consecutive_sequence_optimal(arr,n);
    cout<<len<<endl;

}