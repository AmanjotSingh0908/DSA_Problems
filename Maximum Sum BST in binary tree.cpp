class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    std::array<int, 3> dfs(TreeNode* root, int& ans) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }

        auto leftSubtree = dfs(root->left, ans);
        auto rightSubtree = dfs(root->right, ans);

        if (root->val > leftSubtree[1] && root->val < rightSubtree[0]) {
            int curSum = leftSubtree[2] + rightSubtree[2] + root->val;
            ans = std::max(ans, curSum);

            int minVal = std::min(root->val, leftSubtree[0]);
            int maxVal = std::max(root->val, rightSubtree[1]);

            return {minVal, maxVal, curSum};
        }

        return {INT_MIN, INT_MAX, std::max(leftSubtree[2], rightSubtree[2])};
    }
};
