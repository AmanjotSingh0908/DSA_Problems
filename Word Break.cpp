class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() : isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;  // Mark the end of a word
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie from the wordDict
        TrieNode* root = new TrieNode();
        for (const string& word : wordDict) {
            root->addWord(word);
        }

        int n = s.length();
        vector<bool> dp(n + 1, false);  // dp[i] means substring s[0:i] can be segmented
        dp[0] = true;  // Empty string is always valid

        for (int i = 1; i <= n; ++i) {
            TrieNode* cur = root;
            for (int j = i - 1; j >= 0; --j) {
                if (!dp[j]) continue;  // Skip if s[0:j] cannot be segmented

                // Check if s[j:i] exists in the Trie
                cur = root;
                bool validWord = true;
                for (int k = j; k < i; ++k) {
                    if (cur->children.find(s[k]) == cur->children.end()) {
                        validWord = false;
                        break;
                    }
                    cur = cur->children[s[k]];
                }

                if (validWord && cur->isWord) {  // If s[j:i] is valid
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
