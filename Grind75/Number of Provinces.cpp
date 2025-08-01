class Solution {
public:
    vector<int> parent;

    //find function with path compression
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]); //path compression
        }
        return parent[x];
    }

    //union function
    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB) {
            parent[rootB] = rootA;  //merge the sets
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);

        //initially, each node is its own parent
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        //traverse upper triangle of matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j] == 1){
                    unite(i, j);
                }
            }
        }

        //count number of unique parents
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                provinces ++;
            }
        }
        return provinces;
    }
};
