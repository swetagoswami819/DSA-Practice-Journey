#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>merge(vector<vector<int>>&intervals){
    if(intervals.size()==0) return {};
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0]> ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
        }
      
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