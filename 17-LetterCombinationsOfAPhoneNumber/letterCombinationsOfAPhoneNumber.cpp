#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void result(int index, string output, string digits, vector<string> *ans, string alphabet[]) {
        int number = digits[index] - '0';
        cout << number;
        string str = alphabet[number];
        cout << str;
        cout << str;

        if (index >= int(digits.length())) {
            ans->push_back(output);
            return;
        }

        for (int i = 0; i < int(str.length()); i++) {
            output.push_back(str[i]);
            result(index + 1, output, digits, ans, alphabet);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        cout << "k";
        string alphabet[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        vector<string> ans;
        string output;

        cout << "a";

        if (digits.length() == 0)
            return {};

        result(index, output, digits, &ans, alphabet);

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solution = Solution();
    string digits = argv[1];
    cout << digits << endl;
    vector<string> combs = solution.letterCombinations(digits);
    for (auto comb: combs) {
        cout << comb << endl;
    }
    return 0;
}
