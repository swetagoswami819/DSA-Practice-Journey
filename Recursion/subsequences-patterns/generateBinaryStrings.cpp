// Generate Binary Strings Without Consecutive 1s

// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

// A binary string is a string consisting only of characters '0' and '1'.


// Example 1

// Input: n = 3

// Output: ["000", "001", "010", "100", "101"]

// Explanation: All strings are of length 3 and do not contain consecutive 1s.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void makeString(vector<string>& ds, string &s, int n, int lastChar) {
        if (s.size() == n) {
            ds.push_back(s);
            return;
        }

        // add 0
        s.push_back('0');
        makeString(ds, s, n, 0);
        s.pop_back();

        // add 1
        if (lastChar != 1) {
            s.push_back('1');
            makeString(ds, s, n, 1);
            s.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ds;
        string s = "";
        makeString(ds, s, n, -1);
        return ds;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<string> result = obj.generateBinaryStrings(n);

    cout << "Valid Binary Strings:\n";

    for (string str : result) {
        cout << str << endl;
    }

    return 0;
}