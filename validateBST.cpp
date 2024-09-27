class Solution {
public:
    // Helper function to validate the tree within given bounds
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // Base case: an empty node is valid
        if (node == nullptr) return true;
        
        // If the current node violates the BST property, return false
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        // Recursively check the left and right subtrees
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }

    // Main function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Call the helper with initial infinite bounds
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
