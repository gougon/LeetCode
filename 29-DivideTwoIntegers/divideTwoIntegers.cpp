#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long ans = 0;
        long dd = labs(dividend);
        long dv = labs(divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        while (dd >= dv) {
            long temp = dv;
            long m = 1;
            while (temp << 1 <= dd) {
                temp <<= 1;
                m <<= 1;
            }
            dd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};

int main(int argc, char *argv[]) {
    int dividend = -2147483648;
    int divisor = -1;
    Solution sol = Solution();
    cout << sol.divide(dividend, divisor) << endl;
    return 0;
}
