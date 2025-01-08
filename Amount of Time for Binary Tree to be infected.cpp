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
         int amountOfTime(TreeNode* root, int start) {
        // Step 1: Build the graph using adjacency list
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);
        
        // Step 2: BFS to simulate infection spread
        unordered_map<int, bool> infected;
        queue<int> q;
        q.push(start);
        infected[start] = true;
        int minutes = 0;
        
        // Step 3: Perform BFS
        while (!q.empty()) {
            int size = q.size();
            bool spread = false; // Flag to check if infection spreads in this minute
            
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (!infected[neighbor]) {
                        infected[neighbor] = true;
                        q.push(neighbor);
                        spread = true;
                    }
                }
            }
            
            if (spread) minutes++;
        }
        
        return minutes;
    }
    
private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        if (!node) return;
        
        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }
        
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
};

// Helper function to create a tree from a vector
TreeNode* createTree(const vector<int>& values, int index = 0) {
    if (index >= values.size() || values[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}
    
