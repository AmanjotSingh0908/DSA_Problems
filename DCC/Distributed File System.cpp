#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    int currentNode = 1;

    for (int i = 0; i < F; i++) {
        string fileName;
        int fileSize, replicationFactor;
        cin >> fileName >> fileSize >> replicationFactor;

        int numChunks = ceil(static_cast<double>(fileSize) / 64);
        cout << "File " << fileName << ":" << endl;

        for (int chunk = 1; chunk <= numChunks; chunk++) {
            vector<string> nodes;
            
            for (int j = 0; j < replicationFactor; j++) {
                nodes.push_back("Node " + to_string(currentNode));
                currentNode++;
                if (currentNode > N) {
                    currentNode = 1;
                }
            }

            cout << "Chunk " << chunk << ": ";
            for (int j = 0; j < nodes.size(); j++) {
                cout << nodes[j];
                if (j < nodes.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}

