class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Edge Case: Start or End is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        // Step 1: Initialize DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Step 2: Starting cell
        dp[0][0] = 1;

        // Step 3: Fill first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }

        // Step 4: Fill first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }

        // Step 5: Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        // Step 6: Return the value at destination
        return dp[m-1][n-1];
    }
};
