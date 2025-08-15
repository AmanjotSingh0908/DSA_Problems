#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        set<pair<int, int>> path;

        function<bool(int, int, int)> dfs = [&](int r, int c, int i) {
            if (i == word.size()) return true;
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
                board[r][c] != word[i] || path.count({r, c}))
                return false;

            path.insert({r, c});
            bool res = dfs(r + 1, c, i + 1) ||
                       dfs(r - 1, c, i + 1) ||
                       dfs(r, c + 1, i + 1) ||
                       dfs(r, c - 1, i + 1);
            path.erase({r, c});
            return res;
        };

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};

//T.C: O(n * m * dfs)
//T.C of DFS : 4^len(Word)
//Total T.C: m*n*4^mn
