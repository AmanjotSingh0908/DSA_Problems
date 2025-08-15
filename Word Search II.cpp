struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode() : isWord(false) {
        fill(begin(children), end(children), nullptr);
    }
};

class Solution {
public:
    void addWord(TrieNode* root, const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int ROWS = board.size();
        int COLS = board[0].size();

        // Build trie
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            addWord(root, w);
        }

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        unordered_set<string> resultSet;
        string current;

        function<void(int,int,TrieNode*)> dfs = [&](int r, int c, TrieNode* node) {
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c])
                return;

            char ch = board[r][c];
            int idx = ch - 'a';
            if (!node->children[idx]) return;

            visited[r][c] = true;
            node = node->children[idx];
            current.push_back(ch);

            if (node->isWord) {
                resultSet.insert(current);
            }

            dfs(r-1, c, node);
            dfs(r+1, c, node);
            dfs(r, c-1, node);
            dfs(r, c+1, node);

            visited[r][c] = false;
            current.pop_back();
        };

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(r, c, root);
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
