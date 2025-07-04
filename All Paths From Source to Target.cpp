class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>>&graph, int node){
        path.push_back(node);
        if(node == graph.size() - 1) {
            res.push_back(path);
        } else {
            for(auto nei : graph[node]){
                dfs(graph, nei);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }
};
