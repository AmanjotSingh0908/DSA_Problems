#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 3 sets for rows, columns, and subgrids
        unordered_set<string> rows[9], cols[9], subgrids[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                
                if (current == '.') continue;  // Skip empty cells
                
                string rowKey = "row" + to_string(i) + current;
                string colKey = "col" + to_string(j) + current;
                string subgridKey = "subgrid" + to_string(i / 3) + to_string(j / 3) + current;
                
                // Check if the current value is already in the same row, column, or subgrid
                if (rows[i].count(rowKey) || cols[j].count(colKey) || subgrids[i / 3 * 3 + j / 3].count(subgridKey)) {
                    return false;
                }

                // Add the current value to the corresponding row, column, and subgrid sets
                rows[i].insert(rowKey);
                cols[j].insert(colKey);
                subgrids[i / 3 * 3 + j / 3].insert(subgridKey);
            }
        }
        return true;
    }
};
