class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        long long totalLength = s.size();

        for (int step = 0; step < t; ++step) {
            vector<long long> newFreq(26, 0);

            for (int i = 0; i < 26; ++i) {
                if (i == 25) { // 'z'
                    newFreq[0] = (newFreq[0] + freq[i]) % MOD; // 'a'
                    newFreq[1] = (newFreq[1] + freq[i]) % MOD; // 'b'
                    totalLength = (totalLength + freq[i]) % MOD; // z -> "ab" (length +1)
                } else {
                    newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
                }
            }

            freq = newFreq;
        }

        return totalLength % MOD;
    }
};
