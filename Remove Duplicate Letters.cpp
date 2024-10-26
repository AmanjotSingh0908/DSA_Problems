//Using string approach
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;

        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        // Record the last index of each character
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            lastIndex[ch - 'a'] = i;
        }

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            // If character is already in result, skip it
            if(taken[idx]) {
                continue;
            }

            // Remove characters that are lexicographically larger and appear later
            while(!result.empty() && result.back() > ch && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};
