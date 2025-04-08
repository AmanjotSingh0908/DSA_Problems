class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            unordered_map<int, int> freq;
            bool hasDuplicate = false;

            for (int j = i; j < n; j++) {
                freq[nums[j]]++;
                if (freq[nums[j]] > 1) {
                    hasDuplicate = true;
                    break;
                }
            }

            if (!hasDuplicate) break;

            i += 3;
            ans++;
        }

        return ans;
    }
};
