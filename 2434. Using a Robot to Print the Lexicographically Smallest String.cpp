class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        stack<char> st;
        string result;
        char minChar = 'a';

        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;

            // update minChar to the smallest remaining char
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }

            // pop from stack while top is <= minchar
            while (!st.empty() && st.top() <= minChar) {
                result += st.top();
                st.pop();
            }
        }

        // pop remaining chars
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
