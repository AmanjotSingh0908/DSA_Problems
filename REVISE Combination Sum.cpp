class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // If the current number exceeds the target, no point in continuing
            if (candidates[i] > target) break;
            
            // Choose the current number
            current.push_back(candidates[i]);
            
            // Recurse with the reduced target (i.e., reuse the same number)
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // Backtrack and remove the number
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort candidates to help with pruning
        sort(candidates.begin(), candidates.end());
        
        // Start backtracking from the first index
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
};
