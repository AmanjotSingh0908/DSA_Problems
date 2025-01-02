class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        int medianEl = nums[len/2];
        int count = 0;

        for(int el : nums){
            count += std::abs(el - medianEl);
        }
        return count;
    }
};
