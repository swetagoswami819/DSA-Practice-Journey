#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    struct Meeting {
    int start, end, pos;
};

static bool compare(Meeting m1, Meeting m2) {
    if (m1.end == m2.end) return m1.pos < m2.pos;
    return m1.end < m2.end;
}

int maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<Meeting> meetings(n);

    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i], i + 1};
    }

    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;  
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    return count;
     
       
        
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << sol.maxMeetings(start, end) << endl; // Output: 4
    return 0;
}