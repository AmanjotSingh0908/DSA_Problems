/**
 * @param {number} n
 * @return {boolean}
 */

//NOT FULFILLING TEST CASES

var canAliceWin = function(n) {
    if (n < 10) return false;

    // Dynamic Programming Array
    // dp[i] = true if Alice can win with i stones left, false otherwise.
    const dp = Array(n + 1).fill(false);

    // Fill the DP table
    for (let i = 10; i <= n; i++) {
        // Check if there's any move that makes Bob lose
        for (let stonesToRemove = 10; stonesToRemove > 0; stonesToRemove--) {
            if (i >= stonesToRemove && !dp[i - stonesToRemove]) {
                dp[i] = true;
                break;
            }
        }
    }

    // The result for n stones
    return dp[n];
};
