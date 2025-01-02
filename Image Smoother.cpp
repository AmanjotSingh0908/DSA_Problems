#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();        // Number of rows
        int n = img[0].size();     // Number of columns

        // Directions for the 8 neighbors + the pixel itself
        int x[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        // Resultant smoothed image
        vector<vector<int>> res(m, vector<int>(n));

        // Traverse the image and calculate the smoothed value for each pixel
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;

                // Check all 9 directions (including the pixel itself)
                for (int k = 0; k < 9; k++) {
                    int xi = i + x[k];
                    int yi = j + y[k];

                    // Ensure we stay within the bounds of the image
                    if (xi >= 0 && xi < m && yi >= 0 && yi < n) {
                        sum += img[xi][yi];
                        count++;
                    }
                }

                // Assign the average value to the current pixel
                res[i][j] = sum / count;  // Integer division for floor value
            }
        }
        return res;
    }
};
