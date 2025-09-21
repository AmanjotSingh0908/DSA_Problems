/*
Time Complexity: O(n)
- Building frequency array: O(n)
- Main loop iterates n times: O(n)
- Each character is pushed once and popped once from stack: O(n) total
- minChar updates across all iterations: O(26) = O(1) amortized
- Overall: O(n)

Space Complexity: O(n)
- Stack can hold up to n characters in worst case
- Frequency array: O(26) = O(1)
- Result string: O(n)
- Overall: O(n)
*/
class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {                          // O(n) - build frequency array
            freq[c - 'a']++;
        }

        stack<char> st;
        string result;
        char minChar = 'a';

        for (char c : s) {                          // O(n) - main loop
            st.push(c);                             // O(1)
            freq[c - 'a']--;                        // O(1)

            // update minChar to the smallest remaining char
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {   // O(26) total across all iterations
                minChar++;
            }

            // pop from stack while top is <= minchar
            while (!st.empty() && st.top() <= minChar) {           // Each char popped at most once: O(n) total
                result += st.top();
                st.pop();
            }
        }

        // pop remaining chars
        while (!st.empty()) {                       // O(remaining chars) ≤ O(n)
            result += st.top();
            st.pop();
        }
        return result;
    }
};
