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
    int maxDiameter = 0;

    int height(TreeNode* node){
        if(node == nullptr) return 0;

        int left = height(node->left);
        int right = height(node->right);

        maxDiameter = max(maxDiameter, left + right);
        return max(left, right) + 1;
    };

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};


/*
🔢 Heights of subtrees:
Node 4: height = 1 (leaf)

Node 5: height = 1 (leaf)

Node 2: height = max(1, 1) + 1 = 2

Node 3: height = 1 (leaf)

Node 1: height = max(2, 1) + 1 = 3

🧠 Let's look at the paths:
Path 1: 4 → 2 → 5
Length = 2 (edges)

This path goes through node 2

The height of node 2’s left and right subtrees are both 1

So left + right = 1 + 1 = 2 (exactly the number of edges in that path)

Path 2: 4 → 2 → 1 → 3
Length = 3 (edges)

This path goes through node 1

Heights:

Left subtree (rooted at 2): height = 2

Right subtree (node 3): height = 1

So left + right = 2 + 1 = 3 (again, matches the number of edges)

🧩 So what does this mean?
At any node, the longest path that passes through it is the sum of:

The height of the left subtree

The height of the right subtree

That's why this line is correct:

maxDiameter = max(maxDiameter, left + right);
It's checking, at every node:
👉 “What’s the longest path that passes through this node?”



*/
