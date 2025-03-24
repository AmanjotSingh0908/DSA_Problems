#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read number of nodes (N) and heartbeat threshold (T)
    int N, T;
    cin >> N >> T;

    // Read the last heartbeat times for N nodes
    vector<int> heartbeatTimes(N);
    for (int i = 0; i < N; i++) {
        cin >> heartbeatTimes[i];
    }

    // Read the current time
    int currentTime;
    cin >> currentTime;

    // Check the status of each node
    for (int i = 0; i < N; i++) {
        int difference = currentTime - heartbeatTimes[i];
        
        // Determine status of the node
        if (difference >= T) {
            cout << "Failed" << endl;
        } else {
            cout << "Alive" << endl;
        }
    }

    return 0;
}
