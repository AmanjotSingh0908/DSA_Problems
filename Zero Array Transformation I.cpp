class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        
        // Apply all queries using a difference array
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }
        
        // Compute prefix sum to get total decrements at each index
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            if (nums[i] > curr) return false;  // Not enough decrements possible
        }
        
        return true;
    }
};
