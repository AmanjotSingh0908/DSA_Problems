#include <vector>
#include <cmath>
using namespace std;

/*
Constraint:
O(n) : T.C.
O(1) : S.C.

APPROACH: Cyclic Sort / Array as Hash Table
The key insight is that the first missing positive must be in range [1, n+1]
where n is the array length. We use the array itself as a hash table by placing
each number i at index i-1 (if i is in valid range [1,n]).

ALGORITHM:
1. First pass: Replace all non-positive numbers and numbers > n with a placeholder
2. Second pass: Use array indices as hash - for each valid number, mark its presence
   by making the value at corresponding index negative
3. Third pass: Find the first positive value - its index+1 is the answer
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Replace all numbers <= 0 or > n with (n+1)
        // This ensures all numbers are positive and > n (out of our interest range)
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }
        
        // Step 2: Use array indices as hash table
        // For each number x in range [1,n], mark nums[x-1] as negative
        // This indicates that number x is present in the array
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]); // Get the original value (ignore sign)
            
            // If num is in valid range [1,n], mark its presence
            if (num <= n) {
                // Mark nums[num-1] as negative (num is at index num-1)
                // Use abs() to handle case where it's already negative
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        // Step 3: Find the first missing positive
        // The first positive value at index i means (i+1) is missing
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1; // i+1 is the first missing positive
            }
        }
        
        // If all positions [1,n] are marked (all negative),
        // then the first missing positive is n+1
        return n + 1;
    }
};

/*
DETAILED EXAMPLE WALKTHROUGH:

Example 1: nums = [3,4,-1,1]
Step 1: Replace invalid numbers
- [3,4,-1,1] → [3,4,5,1] (replaced -1 with 5, since 5 > n=4)

Step 2: Mark presence using signs
- i=0: num=3, mark nums[3-1]=nums[2] negative → [3,4,-5,1]
- i=1: num=4, mark nums[4-1]=nums[3] negative → [3,4,-5,-1]  
- i=2: num=5, 5>n so skip
- i=3: num=1, mark nums[1-1]=nums[0] negative → [-3,4,-5,-1]

Step 3: Find first positive
- nums[0]=-3 (negative, so 1 is present)
- nums[1]=4 (positive, so 2 is missing!)
- Return 1+1 = 2

Example 2: nums = [1,2,0]  
Step 1: [1,2,0] → [1,2,4] (replaced 0 with 4)
Step 2: 
- i=0: num=1, mark nums[0] → [-1,2,4]
- i=1: num=2, mark nums[1] → [-1,-2,4]  
- i=2: num=4, 4>n so skip
Step 3: nums[2]=4 (positive), so return 2+1 = 3

TIME COMPLEXITY: O(n)
- Three separate passes through the array
- Each pass is O(n)
- Total: O(n) + O(n) + O(n) = O(n)

SPACE COMPLEXITY: O(1)
- Only using the input array itself for marking
- No additional data structures
- Constant extra variables

KEY INSIGHTS:
1. The answer must be in range [1, n+1]
2. Use array indices as hash table (index i represents number i+1)
3. Use sign of values to mark presence (negative = present)
4. First positive value's index reveals the missing number
*/