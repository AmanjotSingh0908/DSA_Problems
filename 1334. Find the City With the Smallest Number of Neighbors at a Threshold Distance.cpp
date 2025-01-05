class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        //set diagonal to 0
        for(int i=0; i<n; ++i){
            dist[i][i] = 0;
        }

        //fill distance matrix with given edge weights
        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;     //Since the graph is undirected
        }

        //Floyd Warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        //Find the city with the fewest neighbours within distance threshold
        int resultCity = -1;
        int minNeighbors = n;   //taking max vaue i.e n

        for(int i = 0; i<n; i++){
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }

            if(count <= minNeighbors) {
                minNeighbors = count;
                resultCity = i;
            }
        }
        return resultCity;
    }
};
