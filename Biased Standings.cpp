//Greedy Approach
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long int T; 
    cin >> T;

    while (T--) {
        long long int N; // no of teams
        cin >> N;

        vector<long long int> preferredPlaces(N);

        for (long long int i = 0; i < N; i++) {
            string teamName;
            long long int preferred;
            cin >> teamName >> preferred;
            preferredPlaces[i] = preferred;
        }

        // Sort preferred places
        sort(preferredPlaces.begin(), preferredPlaces.end());

        //  minimal badness
        long long int badness = 0;
        for (long long int i = 0; i < N; i++) {
            badness += abs(preferredPlaces[i] - (i + 1));
        }

        cout << badness << endl;
    }

    return 0;
}
