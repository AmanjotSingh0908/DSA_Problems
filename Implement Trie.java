class Trie {

    Trie children[];
    boolean isEnd;

    public Trie() {
        children = new Trie[26];    
    }
    
    public void insert(String word) {
        Trie t = this;
        for(char ch : word.toCharArray()){
            if(t.children[ch - 'a'] == null)
                t.children[ch - 'a'] = new Trie();
            t = t.children[ch - 'a'];
        }
        t.isEnd = true;
    }
    
    public boolean search(String word) {
        Trie t = this;
        for(char ch : word.toCharArray()){
            if(t.children[ch - 'a'] == null)
                return false;
            t = t.children[ch - 'a'];
        }
        return t.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        Trie t = this;
        for(char ch : prefix.toCharArray()){
            if(t.children[ch - 'a'] == null)
                return false;
            t = t.children[ch - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
