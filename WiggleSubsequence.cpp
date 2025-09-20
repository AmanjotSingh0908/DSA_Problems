#include <vector>
#include <algorithm>
using namespace std;

/*
In a wiggle sequence, the differences between adjacent elements strictly alternate between positive and negative.
It's a greedy problem. Time Complexity: O(n) - single pass through the array Space Complexity: O(1) - only two variables used
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int up = 1;   // length of wiggle sequence ending with an upward trend
        int down = 1; // length of wiggle sequence ending with a downward trend
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                // Current element is greater than previous - upward trend
                up = down + 1;  
            }
            else if (nums[i] < nums[i-1]) {
                // Current element is less than previous - downward trend  
                down = up + 1; 
            }
        }
        
        return max(up, down);
    }
};
