#include<bits/stdc++.h>
using namespace std;

//Adding comments in this solution because I thinks its needed, for this solution bcoz is a little tricky problem of two pointer approach with greedy algo's
class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //Sort the platforms so that we can process in order of time 
        sort(Arrival.begin(), Arrival.end()); 
        sort(Departure.begin(),Departure.end());
        int cnt=0; //platforms cnt during train arrival and depart 
        int j=0;
        int i=0;
        int maxi=INT_MIN;  //max platforms needed at any time 

        while(i<Arrival.size()){
            if(Arrival[i]<Departure[j]){  // A train arrives -> platform needed ++
                cnt++;
                i=i+1;
            }
            else{   //A train depart ->platform free --
                cnt--;
                j++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};

int main(){
    Solution sol;
    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<sol.findPlatform(Arrival,Departure)<<endl;
    return 0;
}