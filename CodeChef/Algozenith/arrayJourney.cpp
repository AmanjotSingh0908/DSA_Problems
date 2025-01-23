#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int K;
    cin >> K;

    vector<long long> dp(N, LLONG_MIN);
    dp[0] = arr[0];
    deque<int> dq;
    dq.push_back(0);

    for(int i = 1; i < N; i++){
        while(!dq.empty() && dq.front() < i - K){
            dq.pop_front();
        }

        if(!dq.empty()) {
            dp[i] = dp[dq.front()] + arr[i];
        }

        while(!dq.empty() && dp[dq.back()] <= dp[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        cout << dp[N - 1] << endl;
    }
    return 0;
}

//Better soln byt TLE
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Size of the array
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int K; // Maximum step length
        cin >> K;

        vector<long long> dp(N, LLONG_MIN);
        dp[0] = arr[0];

        // Max heap to store pairs (dp[i], i)
        priority_queue<pair<long long, int>> maxHeap;
        maxHeap.push({dp[0], 0});

        for (int i = 1; i < N; i++) {
            // Remove elements outside the sliding window
            while (!maxHeap.empty() && maxHeap.top().second < i - K) {
                maxHeap.pop();
            }

            // Get the maximum dp value from the heap
            if (!maxHeap.empty()) {
                dp[i] = maxHeap.top().first + arr[i];
            }

            // Add the current dp[i] to the heap
            maxHeap.push({dp[i], i});
        }

        // Output the maximum score to reach the last index
        cout << dp[N - 1] << endl;
    }

    return 0;
}
