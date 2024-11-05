#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // This function converts the board from a 2D array to a vector of strings
    vector<string> boardToString(int n, int board[][20]) {
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    row += 'Q';
                } else {
                    row += '.';
                }
            }
            result.push_back(row);
        }
        return result;
    }

    // This function checks whether it's safe to place a queen at position (x, y)
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
        i = x, j = y;
        while (i >= 0 && j < n) {
            if (board[i][j] == 1) {
                return false;
            }
            i--; j++;
        }
        return true;
    }

    // This function solves the N-Queens problem using backtracking
    void solveNQueen(int n, int board[][20], int i, vector<vector<string>>& solutions) {
        // Base case: if all queens are placed
        if (i == n) {
            solutions.push_back(boardToString(n, board));  // Add the solution to the list
            return;
        }

        // Try placing a queen in every column of row i
        for (int j = 0; j < n; j++) {
            if (canPlace(board, n, i, j)) {
                board[i][j] = 1;  // Place the queen
                solveNQueen(n, board, i + 1, solutions);  // Recurse to place the next queen
                board[i][j] = 0;  // Backtrack
            }
        }
    }

    // Main function to find all the solutions for N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        int board[20][20] = {0};  // Initialize the board with all 0s
        solveNQueen(n, board, 0, solutions);  // Start solving from the first row
        return solutions;
    }
};
