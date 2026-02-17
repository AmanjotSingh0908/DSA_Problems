class Solution {
public:
    int n;
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int dp[51][51][51];
    vector<vector<int>> grid;
    
    bool check(int i, int j) {
        if(i >= 0 && i < n && j >= 0 && j < n) return true;
        return false;
    }
    
    int rec(int i, int j, int a) {
        int b = i + j - a;
        
        // Base case: reached bottom-right
        if(i == n - 1 && j == n - 1) {
            return grid[i][j];
        }
        
        // Check if already computed
        if(dp[i][j][a] != -1) return dp[i][j][a];
        
        // Calculate initial cost for current cells
        int initial_cost = grid[i][j] + grid[a][b];
        if(i == a && j == b) {
            initial_cost = grid[i][j];  // Same cell, count only once
        }
        
        int ans = -1e9;  // Initialize to very negative value
        
        // Try all 4 combinations of moves for both paths
        for(int k1 = 0; k1 < 2; k1++) {
            for(int k2 = 0; k2 < 2; k2++) {
                int ni = i + dx[k1];
                int nj = j + dy[k1];
                int na = a + dx[k2];
                int nb = b + dy[k2];
                
                if(check(ni, nj) && check(na, nb)) {
                    // Check for thorns (-1)
                    if(grid[ni][nj] != -1 && grid[na][nb] != -1) {
                        ans = max(ans, initial_cost + rec(ni, nj, na));
                    }
                }
            }
        }
        
        return dp[i][j][a] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        
        // Check if start or end has thorn
        if(grid[0][0] == -1 || grid[n-1][n-1] == -1) {
            return 0;
        }
        
        // Initialize DP table
        memset(dp, -1, sizeof(dp));
        
        int ans = rec(0, 0, 0);
        
        // If no valid path exists, return 0
        return max(0, ans);
    }
};
