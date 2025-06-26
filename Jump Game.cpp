class Solution {
public:
    bool canJumpFrom(int index, vector<int>& nums, vector<int>& dp){
        if(index >= nums.size() - 1) return true;
        if(dp[index] != -1) return dp[index];

        int maxJump = nums[index]; //choice

        for(int step = 1; step <= maxJump; step++){
            if(canJumpFrom(index + step, nums, dp)){
                return dp[index] = true;    //move and memoise
            }
        }
        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return canJumpFrom(0, nums, dp);
    }
};
