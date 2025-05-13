class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            optimal sub structure - any DP is not possible wihtout optimal sub structure
                11 - minimum no. of coins to make total amount of 11
                / \
               /   \
              10    9 (minimum no. of coins to make total amount of 9)
    (minimum no. of coints to make total amt of 10)

            x -> coins including ith coin
            y -> minimum of coins exluding ith coin

            x = f(i+1,sum)
            y = f(i+2, sum)
        */
        vector<int> memo(amount + 1, -1);
        int result = minCoins(coins,amount,memo);
        return result == INT_MAX ? -1 : result;
    }

private:
    int minCoins(vector<int>& coins, int amount, vector<int>& memo){
        if (amount == 0) return 0;         // Base case: 0 coins for amount 0
        if (amount < 0) return INT_MAX;    // Not possible to form negative amount

        if (memo[amount] != -1) return memo[amount]; // Return memoized result

        int min_count = INT_MAX;

        for (int coin : coins) {
            int res = minCoins(coins, amount - coin, memo);
            if (res != INT_MAX) {
                min_count = min(min_count, res + 1); // +1 for the current coin
            }
        }

        memo[amount] = min_count;
        return min_count;
    }
};
