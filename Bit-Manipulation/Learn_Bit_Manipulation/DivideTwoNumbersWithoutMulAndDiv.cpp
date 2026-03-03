#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool sign = (dividend > 0) == (divisor > 0);

        // Convert to positive using long long (SAFE)
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;

            // Find highest multiple using bit shifting
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        return sign ? quotient : -quotient;
    }
};

int main() {
    Solution sol;

    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    int result = sol.divide(dividend, divisor);

    cout << "Quotient = " << result << endl;

    return 0;
}