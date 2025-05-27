class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int old_color, int new_color) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != old_color) {
            return;
        }
        grid[i][j] = new_color;
        dfs(grid, i + 1, j, old_color, new_color);
        dfs(grid, i - 1, j, old_color, new_color);
        dfs(grid, i, j + 1, old_color, new_color);
        dfs(grid, i, j - 1, old_color, new_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& grid, int i, int j, int new_color) {
        int old_color = grid[i][j];
        if (old_color == new_color) {
            return grid;
        }
        dfs(grid, i, j, old_color, new_color);
        return grid;
    }
};
//Above solution uses DFS approach
//Can solve it using BFS (queue) also
