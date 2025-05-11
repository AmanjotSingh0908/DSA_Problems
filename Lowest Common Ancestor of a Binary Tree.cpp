/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;

    void dfs(TreeNode* node, TreeNode* par, int d) {
        if (!node) return;
        parent[node] = par;
        depth[node] = d;
        dfs(node->left, node, d + 1);
        dfs(node->right, node, d + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr, 0); // preprocess parents and depths

        // Make p the deeper node
        if (depth[p] < depth[q]) swap(p, q);

        int diff = depth[p] - depth[q];

        // Climb p up until it's at the same depth as q
        while (diff--) {
            p = parent[p];
        }

        // Climb both until they meet
        while (p != q) {
            p = parent[p];
            q = parent[q];
        }

        return p;
    }
};
