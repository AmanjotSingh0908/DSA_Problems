//Add Tabulation in future
//Memeoization + Recursion
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //Recursion + Memoization
        //Apply Tabulation -- bottom up 1 to n-1
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);

    }

    int f(int ind, int T, vector<int>& coins, vector<vector<int>> dp){
        if(ind == 0){
            return (T % coins[0] ==  0);
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int nonTake = f(ind-1, T, coins, dp);
        int Take = 0;

        if(coins[ind] <= T) Take = f(ind, T - coins[ind], coins, dp);
        return dp[ind][T] = Take + nonTake;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //Recursion + Memoization
        //Apply Tabulation -- bottom up 1 to n-1
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int T = 0; T <= amount; T++){
            dp[0][T] = (T % coins[0] ==  0);
        }
        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T<=amount; T++){
                int nonTake = dp[ind-1][T];
                int Take = 0;

                if(coins[ind] <= T) Take = dp[ind][T - coins[ind]];
                   dp[ind][T] = Take + nonTake;
                }
        }
        return dp[n-1][amount];

    }

    int f(int ind, int T, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            return (T % coins[0] ==  0);
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int nonTake = f(ind-1, T, coins, dp);
        int Take = 0;

        if(coins[ind] <= T) Take = f(ind, T - coins[ind], coins, dp);
        return dp[ind][T] = Take + nonTake;
    }
};
