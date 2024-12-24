class Trie
{
    public Trie[] children;
    int links;  //by default 0
    boolean isEnd;  //by default false

    public Trie(){
        children = new Trie[26];
    }

    public void insert(String word){
        Trie t = this;
        for(char ch : word.toCharArray()){
            if(t.children[ch - 'a'] == null){
                t.links++;
                t.children[ch - 'a'] = new Trie();
            }
            t = t.children[ch - 'a'];
        }
        t.isEnd = true;
    }
}


class Solution {
    public String longestCommonPrefix(String[] strs) {
        Trie root = new Trie();

        for(String word : strs){
            root.insert(word);
        }
        Trie t = root;
        StringBuilder ans = new StringBuilder(); //Answer
        while(t.links == 1 && !t.isEnd)
        {
            for(int i = 0; i < 26; i++)
            {
                if(t.children[i] != null)
                {
                    ans.append((char)('a' + i));
                    t = t.children[i];
                    break;
                }
            }
        }
        return ans.toString();
    }
}
