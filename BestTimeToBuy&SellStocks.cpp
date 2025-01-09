//DP + Memoization
class Solution {
public:
    long f(int ind, int buy, vector<int>& prices, int n, vector<vector<long>> &dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1, 0, prices,n,dp),
                        0 + f(ind+1, 1,prices,n,dp)
            );
        } else {
            profit = max(prices[ind] + f(ind+1, 1,prices,n,dp),
                        0 + f(ind+1, 0,prices,n,dp)
            );
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2,-1));
        return f(0,1,prices, n,dp);
    }
};

//T.C of Memoization = O (Nx2)
//S.C of Memeizatio = O (Nx2) + O(N) --> to remove O(N) we do tabulation

#include <iostream>
#include <vector>
#include <algorithm>  // For max()

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                long profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


