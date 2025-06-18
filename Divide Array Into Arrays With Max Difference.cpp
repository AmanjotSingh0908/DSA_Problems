class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        vector<vector<int>> result;

        // Step 2: Loop through the array in steps of 3
        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Step 3: Check the difference
            if (c - a > k) {
                return {}; // If the max difference > k, return empty
            }

            // Step 4: Add the valid group to the result
            result.push_back({a, b, c});
        }

        return result;
    }
};
