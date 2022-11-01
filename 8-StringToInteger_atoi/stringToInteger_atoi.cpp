#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
        ignore leading whitespace
        need to read +/-
        read until non-digit appear
        0032 = 32
        if no digit return +/- 0
        */
        bool sign = true;
        int i = 0;
        while (s[i] == ' ') i++;
        
        char c = s[i];
        if (c == '-' || c == '+')
            sign = (s[i++] == '+');

        int ret = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && digit > INT_MAX % 10) {
                if (!sign) return INT_MIN;
                else return INT_MAX; 
            }

            ret = ret * 10 + digit;
            i++;
        }
        return (sign ? 1 : -1) * ret;
    }
};

int main(int argc, char *argv[])
{
    string s = "4193 with";
    Solution solution = Solution();
    cout << solution.myAtoi(s) << endl;
    return 0;
}
