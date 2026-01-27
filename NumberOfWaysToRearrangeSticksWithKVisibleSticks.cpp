class Solution {
public:
const int MOD = 1e9 + 7;
int dp[1005][1005];

    int solve(int n, int k){
        //Base cases
        if(n == 0 && k == 0) return 1;
        if(n == 0 || k == 0) return 0;
        if(k > n) return 0;

        //cache check
        if(dp[n][k] != -1) return dp[n][k];

        long long case1 = solve(n-1, k-1);
        /*
            Still need k visible from remaining n-1 sticks
    Can place n in (n-1) positions
    Ways: dp[n-1][k] * (n-1)
        */
        long long case2 = ((long long)solve(n-1, k) * (n-1)) % MOD;
        return dp[n][k] = (case1 + case2) % MOD;
    }

    int rearrangeSticks(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(n, k);

    }
};
