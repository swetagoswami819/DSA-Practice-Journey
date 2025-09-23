#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double, int>> ratioIndex; 
        
       
        for (int i = 0; i < n; i++) {
            ratioIndex.push_back({(double)val[i]/wt[i], i});
        }
        
       
        sort(ratioIndex.rbegin(), ratioIndex.rend());
        
        double total = 0.0;
        
        for (auto &p : ratioIndex) {
            int i = p.second;
            if (wt[i] <= capacity) {
                total += val[i];
                capacity -= wt[i];
            } else {
                total += p.first * capacity;
                break;
            }
        }
        
        return total;
    }
};

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    Solution sol;
    double maxValue = sol.fractionalKnapsack(val, wt, capacity);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}