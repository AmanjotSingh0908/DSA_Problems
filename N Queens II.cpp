class Solution {
public:
    bool canPlace(int board[][20], int n, int x, int y) {
        // Check column
        for (int k = 0; k < x; k++) {
            if (board[k][y] == 1) {
                return false;
            }
        }

        // Check left diagonal
        int i = x, j = y;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i--; j--;
        }

        // Check right diagonal
        i = x; j = y;
        while (i >= 0 && j < n) {
            if (board[i][j] == 1) {
                return false;
            }
            i--; j++;
        }

        return true;
    }

    void solveNQueen(int board[][20], int n, int i, int& solutions) {
        if (i == n) {
            solutions++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (canPlace(board, n, i, j)) {
                board[i][j] = 1;
                solveNQueen(board, n, i + 1, solutions);
                board[i][j] = 0; // backtrack
            }
        }
    }

    int totalNQueens(int n) {
        int board[20][20] = {0};
        int solutions = 0;
        solveNQueen(board, n, 0, solutions);
        return solutions;
    }
};
