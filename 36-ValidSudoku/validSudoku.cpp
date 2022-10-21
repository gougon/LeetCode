#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), blocks(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];

                if (cur == '.') continue;
                
                if (rows[i].count(cur) || cols[j].count(cur) || blocks[(i / 3) * 3 + j / 3].count(cur))
                    return false;
                
                rows[i].insert(cur);
                cols[j].insert(cur);
                blocks[(i / 3) * 3 + j / 3].insert(cur);
            }
        }

        return true;
    }

    unordered_map<char, int> makeRuleValidator() {
        unordered_map<char, int> ruleValidator;
        for (int i = 1; i < 10; i++) {
            ruleValidator[i + '0'] = 1;
        }
        return ruleValidator;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> board(
        {{'.','.','.','.','5','.','.','1','.'}
        ,{'.','4','.','3','.','.','.','.','.'}
        ,{'.','.','.','.','.','4','.','.','7'}
        ,{'8','.','.','.','.','.','.','2','.'}
        ,{'.','.','2','.','7','.','.','.','.'}
        ,{'.','1','5','.','.','.','.','.','.'}
        ,{'.','.','.','.','.','2','.','.','.'}
        ,{'.','2','.','9','.','.','.','.','.'}
        ,{'.','.','4','.','.','.','.','.','.'}}
    );

    Solution sol = Solution();
    bool ans = sol.isValidSudoku(board);

    cout << ans << endl;
    return 0;
}
