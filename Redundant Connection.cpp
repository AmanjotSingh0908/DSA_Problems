class Solution {
private:
    vector<int> parent;
    vector<int> size;

    int findRoot(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unionSets(int node1, int node2){
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);

        if(root1 == root2){
            return false;
        }

        // Union by size (attach smaller tree under the bigger one)
        if(size[root1] > size[root2]){
           parent[root2] = root1;
            size[root1] += size[root2];
        } else {
            parent[root1] = root2;
            size[root2] += size[root1];
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numberOfNodes = edges.size();
        parent.resize(numberOfNodes + 1);
        size.assign(numberOfNodes + 1, 1);

        for(int i = 1; i <= numberOfNodes; i++){
            parent[i] = i;
        }

        for(const vector<int>& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];

            if(!unionSets(node1, node2)){
                return edge;    //this edge forms cycle
            }
        }

        return {};
    }
};
