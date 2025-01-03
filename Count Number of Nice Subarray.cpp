class Solution {
public:
int atMostK(const vector<int>& nums, int k) {
    int count = 0, oddCount = 0, left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        if (nums[right] % 2 != 0) { // Odd number
            oddCount++;
        }
        
        while (oddCount > k) {
            if (nums[left] % 2 != 0) {
                oddCount--;
            }
            left++;
        }

        count += right - left + 1; // All subarrays from left to right
    }
    return count;
}


    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
