class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = 0;
        int maxEven = s.size();

        for (auto [ch, count] : freq) {
            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
            } else {
                maxEven = min(maxEven, count);
            }
        }

        // Return the difference between max odd and max even frequency
        return maxOdd - maxEven;
    }
};
