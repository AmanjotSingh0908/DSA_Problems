#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int h;
    cin >> h;

    int n = h * (h + 1) / 2; 
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> triangle(h);
    int index = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i].push_back(arr[index++]);
        }
    }

    for (int i = 0; i < h - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!(triangle[i][j] < triangle[i + 1][j] && triangle[i][j] < triangle[i + 1][j + 1])) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}