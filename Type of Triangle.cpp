class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        
        int a = nums[0], b = nums[1], c = nums[2];

        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
