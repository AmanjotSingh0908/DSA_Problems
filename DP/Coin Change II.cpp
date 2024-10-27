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
