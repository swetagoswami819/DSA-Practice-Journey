#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    vector<string> addOperators(string s, int target)
    {
        ans.clear(); // important if reused
        helper(s, target, 0, "", 0, 0);
        return ans;
    }

    void helper(string s, int target, int i, string path,
                long long eval, long long residual)
    {

        if (i == s.size())
        {
            if (eval == target)
            {
                ans.push_back(path);
            }
            return;
        }

        string currentStr = "";
        long long num = 0;

        for (int j = i; j < s.size(); j++)
        {

            // prevent numbers like 05, 00 etc.
            if (j > i && s[i] == '0')
                break;

            currentStr += s[j];
            num = num * 10 + (s[j] - '0');

            if (i == 0)
            {
                helper(s, target, j + 1, currentStr, num, num);
            }
            else
            {
                helper(s, target, j + 1,
                       path + "+" + currentStr,
                       eval + num, num);

                helper(s, target, j + 1,
                       path + "-" + currentStr,
                       eval - num, -num);

                helper(s, target, j + 1,
                       path + "*" + currentStr,
                       eval - residual + residual * num,
                       residual * num);
            }
        }
    }
};

int main()
{
    Solution obj;

    string num;
    int target;

    cout << "Enter number string: ";
    cin >> num;

    cout << "Enter target: ";
    cin >> target;

    vector<string> result = obj.addOperators(num, target);

    if (result.empty())
    {
        cout << "[]" << endl;
    }
    else
    {
        cout << "Valid Expressions:\n";
        for (auto &exp : result)
        {
            cout << exp << endl;
        }
    }

    return 0;
}