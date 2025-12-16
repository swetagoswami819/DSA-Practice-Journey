#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    if(intervals.size()==0) return ;
    int n  = intervals.size(); 
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>ans;

    for(int i =0; i<intervals.size();i++){

        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
        for(int j = i+1 ;j<n;j++){
            if(intervals[j][0]<=end){
                end= max(end , intervals[j][1]);
            }
            else{
                break;
            }

        }
        ans.push_back({start , end});
    
    }
    return ans;

}

int main(){
    vector<vector<int>>intervals = {{1,3},{2,4},{5,7},{6,8}};
    vector<vector<int>>mergedIntervals = merge(intervals);

    for(const auto& interval : mergedIntervals){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}