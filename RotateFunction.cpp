#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int f0 = 0;

        // Calculate F(0)
        for (int i = 0; i < size; ++i) {
            f0 += i * nums[i];
        }

        int max_fn = f0;
        int prev_fn = f0;

        // Iterate through the array to compute other F(k)
        for (int i = size - 1; i > 0; --i) {
            int next_fn = prev_fn + total_sum - size * nums[i];
            max_fn = max(max_fn, next_fn);
            prev_fn = next_fn;
        }

        return max_fn;
    }
};
