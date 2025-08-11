/*
Build the adjacency list for the graph.
Calculate indegree (number of prerequisites) for each node.
Push all nodes with indegree 0 into a queue (they can be taken immediately).
Process the queue:
    Pop a node.
    Add it to your topological order.
    For each of its neighbors, reduce their indegree.
    If a neighbor’s indegree hits 0, push it into the queue.

If you processed all nodes, you have a valid topological order.
If not, there was a cycle, so no valid ordering exists.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        int indegree[numCourses];
        fill(indegree, indegree + numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // Node is in your topo sort
            // so please remove it from the indegree
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        return topo.size() == numCourses;
    }
};
