#include <sstream>
#include <string>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string. -> preorder traversal
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        string result = to_string(root->val) + ",";
        result += serialize(root->left);    //serialize left subtree
        result += serialize(root->right);   //serialize right subtree
        return result;
    }

    // Helper function to split the serialized string by commas
    TreeNode* deserializeHelper(stringstream &ss) {
        string val;
        getline(ss, val, ',');

        if(val == "null"){
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node -> left = deserializeHelper(ss);
        node -> right = deserializeHelper(ss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/*
Serialize: O(n) - visit each node once
Deserialize: O(n) - process each token once
Space: O(n) - for the serialized string and recursion stack

Tree:     1
         / \
        2   3
           / \
          4   5

Preorder: 1,2,null,null,3,4,null,null,5,null,null
*/