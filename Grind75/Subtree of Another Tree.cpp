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
    string preOrderTraversal(TreeNode* node){
        if(node == nullptr){
            return "null ";
        }

        stringstream ss;
        ss << "#" << node->val << " ";
        ss << preOrderTraversal(node->left);
        ss << preOrderTraversal(node->right);
        return ss.str();
    }
//op of the preOrderTraversal(root) will be:
// "#1 #2 null null #3 null null "

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string fullTree = preOrderTraversal(root);
        string subTree = preOrderTraversal(subRoot);
        return fullTree.find(subTree) != string::npos;
    }
};
