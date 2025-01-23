#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long M, N;
    cin >> M >> N;

    vector<long long> difficulties(N);
    long long totalXor = 0;

    // Read all difficulty values and calculate their XOR
    for (int i = 0; i < N; ++i) {
        cin >> difficulties[i];
        totalXor ^= difficulties[i];
    }

    // Determine the total difficulty based on M
    if (M % 2 == 0) {
        cout << 0 << endl; // Even M
    } else {
        cout << (totalXor % MOD) << endl; // Odd M
    }

    return 0;
}
