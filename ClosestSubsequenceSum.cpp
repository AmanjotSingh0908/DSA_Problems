class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        // Split array into two halves for meet-in-the-middle
        int mid = n / 2;
        
        // Generate all possible sums for first half
        vector<int> leftSums;
        generateSums(nums, 0, mid, 0, leftSums);
        
        // Generate all possible sums for second half
        vector<int> rightSums;
        generateSums(nums, mid, n, 0, rightSums);
        
        // Sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());
        
        int minDiff = abs(goal);
        
        // For each sum in left half, find best match in right half
        for(int leftSum : leftSums) {
            int target = goal - leftSum;
            
            // Binary search for closest value to target in rightSums
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            
            // Check the found position
            if(it != rightSums.end()) {
                minDiff = min(minDiff, abs(leftSum + *it - goal));
            }
            
            // Check the previous position
            if(it != rightSums.begin()) {
                --it;
                minDiff = min(minDiff, abs(leftSum + *it - goal));
            }
        }
        
        return minDiff;
    }
    
private:
    void generateSums(vector<int>& nums, int start, int end, int currentSum, vector<int>& sums) {
        if(start == end) {
            sums.push_back(currentSum);
            return;
        }
        
        // Don't include current element
        generateSums(nums, start + 1, end, currentSum, sums);
        
        // Include current element
        generateSums(nums, start + 1, end, currentSum + nums[start], sums);
    }
};
