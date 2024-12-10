class Solution {
public:
    //Using Combinatorical formula --  C(n, k) = C(n-1, k-1) + C(n-1, k), where C(n, k) represents the binomial coefficient
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i<numRows; i++){
            vector<int> row(i + 1, 1);
            for(int j = 1; j<i; j++) {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
