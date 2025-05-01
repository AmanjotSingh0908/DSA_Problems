class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = min((i != 0 ? ans[i-1] : INT_MAX), cost[i]);
        }
            return ans;

    }
};
