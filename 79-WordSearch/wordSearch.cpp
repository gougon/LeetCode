#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        _h = board.size();
        _w = board[0].size();

        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                if (board[i][j] != word[0])
                    continue;

                if (search(board, word, j, i, 0))
                    return true;
            }
        }
        return false;
    }
private:
    int _w;
    int _h;

    bool search(vector<vector<char>>& board, string word, int x, int y, int len) {
        if (y >= _h || y < 0 || x >= _w || x < 0 || board[y][x] != word[len])
            return false;

        if (len == word.size() - 1)
            return true;

        char cur = board[y][x];
        board[y][x] = 0;
        bool found = search(board, word, x + 1, y, len + 1) ||
                     search(board, word, x - 1, y, len + 1) || 
                     search(board, word, x, y + 1, len + 1) || 
                     search(board, word, x, y - 1, len + 1);
        board[y][x] = cur;
        return found;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> board({
        {'A','B','C','E'},
        {'S','F','B','S'},
        {'A','D','E','E'}
    });
    string word = "ABCBED";
    Solution sol = Solution();
    cout << sol.exist(board, word) << endl;
    return 0;
}
