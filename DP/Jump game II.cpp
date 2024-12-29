//TLE 
class Solution {
public:


int min_jumps(vector<int> & nums, int n, vector<int> dp, int i =0){
    if( i == n-1){
        return 0;
    }
    if( i >= n){
        return INT_MAX;
    }

    if(dp[i] != 0){
        return dp[i];
    }

    int steps = INT_MAX;
    int max_jump = nums[i];

    for(int jump = 1; jump <= max_jump; jump++){
        int next_cell = i + jump;
        int subprob = min_jumps(nums,n,dp,next_cell);
        if(subprob!=INT_MAX){
            steps = min(steps, subprob + 1);
        }
    }
    return dp[i] = steps;
}



    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,0);

        return min_jumps(nums,n,dp,0);
    }
};



//No TLE 
/**
To optimize it, I suggest two main fixes:
Use a better base case for the memoization (dp[i]): Right now, you're checking for dp[i] != 0, but 0 is being used as an uncomputed value, 
which may conflict with valid results. It's better to use -1 (or any other invalid number) to represent "uncomputed" and avoid ambiguity 
with the result 0 itself. Pass the dp array by reference: Your dp array is currently passed by value to the recursive calls, which results 
in creating new copies of dp on each recursive call. This increases memory and computation overhead. Passing dp by reference will fix this.
**/

class Solution {
public:

    int min_jumps(vector<int>& nums, int n, vector<int>& dp, int i = 0) {
        if (i == n - 1) {
            return 0;
        }
        if (i >= n) {
            return INT_MAX;
        }

        if (dp[i] != -1) {  // Changed from dp[i] != 0 to dp[i] != -1 to handle memoization properly
            return dp[i];
        }

        int steps = INT_MAX;
        int max_jump = nums[i];

        for (int jump = 1; jump <= max_jump; jump++) {
            int next_cell = i + jump;
            int subprob = min_jumps(nums, n, dp, next_cell);
            if (subprob != INT_MAX) {
                steps = min(steps, subprob + 1);
            }
        }

        dp[i] = steps;
        return steps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Handle edge case where no jumps are needed.

        vector<int> dp(n, -1); // Changed initialization to -1 for uncomputed values
        return min_jumps(nums, n, dp, 0);
    }
};

