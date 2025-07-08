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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        return node;
    }
};


//One more try but not successful
/*
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
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;

        TreeNode* root = new TreeNode(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            insertToBST(root, nums[i]);
        }
        return root;
    }

private:
    TreeNode* insertToBST(TreeNode* root, int val){
        TreeNode* current = root;
        while(true) {
            if(val < current-> val){
                if(!current->left){
                    current->left = new TreeNode(val);
                    break;
                }
                current = current -> left;
            } else {
                if(!current -> right){
                    current -> right = new TreeNode(val);
                    break;
                }
                current = current->right;
            }
        }
        return root;
    }
};
*/
