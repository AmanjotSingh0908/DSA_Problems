class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0); // Only 3 colors: 0, 1, 2

        for (int num : nums) {
            freq[num]++;
        }

        nums.clear(); // Clear original vector

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < freq[i]; j++) {
                nums.push_back(i);
            }
        }
    }
};
