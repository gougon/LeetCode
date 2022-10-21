#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef struct romanMap {
        int integer;
        string roman;
    } romanMap;
public:
    string intToRoman(int num) {
        vector<romanMap> romanMapList = {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" }
        };

        string roman = "";
        for (auto curRomanMap: romanMapList) {
            if (num < curRomanMap.integer)
                continue;
            int integer = num / curRomanMap.integer;
            roman += repeat(curRomanMap.roman, integer);
            num = num % curRomanMap.integer;
        }
        roman += "\n";

        return roman;
    }

    string repeat(string str, int times) {
        string rstr = "";
        for (int i = 0; i < times; i++)
            rstr += str;
        rstr += "\0";
        return rstr;
    }
};

int main()
{
    Solution solution = Solution();
    cout << solution.intToRoman(3849);
    return 0;
}
