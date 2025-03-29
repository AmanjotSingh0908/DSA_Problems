class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        sort(nums.begin(), nums.end());
        int maxdiff = INT_MIN;
        for(int i = 0; i < n-1; i++){
            maxdiff = max(diff, nums[i+1] - nums[i]);
        }
        return maxdiff;
    }
};
