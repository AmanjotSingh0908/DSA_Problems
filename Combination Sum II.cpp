class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, vector<int>& path, int start){
        if(target == 0){
            result.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            //skip duplicates
            if(i > start && candidates[i] == candidates[i - 1]) continue;

            //if number is too big,no need to continue
            if(candidates[i] > target) break;

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<int> path;
      backtrack(candidates, target, path, 0);
      return result;
    }
};
