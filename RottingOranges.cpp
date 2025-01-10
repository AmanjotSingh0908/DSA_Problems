class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        bool changed = false;
        int no = 2;

        // Helper function to check the position is valid
        auto isSafe = [&](int i, int j) {
            return i >= 0 && i < rows && j >= 0 && j < cols;
        };

        while (true) {
            changed = false;  // Reset changed flag at the start of each round

            // Traverse the grid and rot all adjacent fresh oranges
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == no) {
                        // Rot adjacent oranges
                        if (isSafe(i + 1, j) && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = grid[i][j] + 1;
                            changed = true;
                        }
                        if (isSafe(i, j + 1) && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = grid[i][j] + 1;
                            changed = true;
                        }
                        if (isSafe(i - 1, j) && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = grid[i][j] + 1;
                            changed = true;
                        }
                        if (isSafe(i, j - 1) && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = grid[i][j] + 1;
                            changed = true;
                        }
                    }
                }
            }

            // If no oranges were rotten in this round, break the loop
            if (!changed) break;

            no++;  // Increase the rotting level
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;  // Fresh orange is still present
            }
        }

        return no - 2;
    }
};
