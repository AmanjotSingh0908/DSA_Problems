#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(const vector<vector<int>> &prefix, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0) return 0;
    int sum = prefix[x2][y2];
    if (x1 > 0) sum -= prefix[x1 - 1][y2];
    if (y1 > 0) sum -= prefix[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) sum += prefix[x1 - 1][y1 - 1];
    return sum;
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));
    vector<vector<int>> prefix(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> matrix[i][j];
            prefix[i][j] = matrix[i][j];
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int X, Y, K;
        cin >> X >> Y >> K;

        int low = 0, high = min(R, C) / 2, best = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int x1 = X - mid, y1 = Y - mid;
            int x2 = X + mid, y2 = Y + mid;

            if (x1 >= 0 && y1 >= 0 && x2 < R && y2 < C) {
                int blackCells = getSum(prefix, x1, y1, x2, y2);
                if (blackCells <= K) {
                    best = 2 * mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                high = mid - 1;
            }
        }

        cout << best * best << endl;
    }

    return 0;
}


//Another solution
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the sum of black cells in a submatrix
int getSum(const vector<vector<int>> &prefix, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0) return 0;
    int sum = prefix[x2][y2];
    if (x1 > 0) sum -= prefix[x1 - 1][y2];
    if (y1 > 0) sum -= prefix[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) sum += prefix[x1 - 1][y1 - 1];
    return sum;
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));
    vector<vector<int>> prefix(R, vector<int>(C, 0));

    // Input matrix and build prefix sum
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> matrix[i][j];
            prefix[i][j] = matrix[i][j];
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int X, Y, K;
        cin >> X >> Y >> K;

        int low = 0, high = min({R, C}) / 2, best = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int x1 = X - mid, y1 = Y - mid;
            int x2 = X + mid, y2 = Y + mid;

            if (x1 >= 0 && y1 >= 0 && x2 < R && y2 < C) {
                int blackCells = getSum(prefix, x1, y1, x2, y2);
                if (blackCells <= K) {
                    best = 2 * mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                high = mid - 1;
            }
        }

        cout << best * best << endl;
    }

    return 0;
}
