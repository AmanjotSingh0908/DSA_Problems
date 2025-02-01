class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndofWord = false;
    };
    TrieNode *root; //Root of the trie

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndofWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    private:
        bool searchHelper(const string& word, int index, TrieNode* node){
            if(index == word.size()){
                return node->isEndofWord;
            }
            char c = word[index];
            if (c == '.'){
                for(int i = 0; i < 26; ++i){
                    if(node->children[i] != nullptr && searchHelper(word,index+1, node->children[i])) {
                        return true;
                    }
                }
            } else {
                int childIndex = c - 'a';
                if(node -> children[childIndex] != nullptr) {
                    return searchHelper(word, index+1, node->children[childIndex]);
                }
            }
            return false;
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
