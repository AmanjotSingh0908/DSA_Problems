//STL: Set and approached problem with 2 pointers
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        int totalDistinct = uniqueElements.size();

        unordered_map<int, int> windowFreq;
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            windowFreq[nums[right]]++;

            while (windowFreq.size() == totalDistinct) {
                ans += (n - right);  
                windowFreq[nums[left]]--;
                if (windowFreq[nums[left]] == 0) {
                    windowFreq.erase(nums[left]);
                }
                left++;
            }
        }

        return ans;
    }
};
