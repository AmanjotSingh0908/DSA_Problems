/*
So the default sort will:

Sort by digit sum (digitSum(nums[i]))

If digit sums are equal, sort by the number itself (nums[i])

If both are equal (won’t happen here since numbers are distinct), then use the original index


*/

class Solution {
public:
    // Helper to compute digit sum
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create a vector of {digitSum, num, originalIndex}
        vector<tuple<int, int, int>> sortedList;
        for (int i = 0; i < n; ++i) {
            sortedList.emplace_back(digitSum(nums[i]), nums[i], i);
        }

        // Sort based on digitSum and then num
        sort(sortedList.begin(), sortedList.end());

        // Create a map from sorted position to original index
        vector<int> indexMapping(n);
        for (int i = 0; i < n; ++i) {
            indexMapping[i] = get<2>(sortedList[i]);  // original index of sorted[i]
        }

        // Count cycles in indexMapping
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || indexMapping[i] == i)
                continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexMapping[j];
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += (cycleSize - 1);
        }

        return swaps;
    }
};
