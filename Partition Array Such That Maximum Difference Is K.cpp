class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0;
        int n = nums.size();

        while(i < n) {
            int start = nums[i];
            count++;
            while(i < n && nums[i] - start <= k){
                i++;
            }
        }
        return count;
    }
};
