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


