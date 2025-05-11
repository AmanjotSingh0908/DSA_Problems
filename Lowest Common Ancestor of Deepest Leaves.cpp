/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function returns {LCA, depth}
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};

        auto [leftNode, leftDepth] = dfs(node->left);
        auto [rightNode, rightDepth] = dfs(node->right);

        if (leftDepth == rightDepth) {
            return {node, leftDepth + 1};
        } else if (leftDepth > rightDepth) {
            return {leftNode, leftDepth + 1};
        } else {
            return {rightNode, rightDepth + 1};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
