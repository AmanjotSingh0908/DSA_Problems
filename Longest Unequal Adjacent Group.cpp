class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        if(words.empty()) return res;

        res.push_back(words[0]);
        int lastGroup = groups[0];

        for(int i = 1; i < words.size(); i++){
            if(groups[i] != lastGroup){
                res.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        return res;
    }
};
