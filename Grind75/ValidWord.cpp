class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for(char c : word){
            if(!isalnum(c)) return false;

            if(isalpha(c)) {
                char lowerC = tolower(c);
                if(lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'u' || lowerC == 'o'){
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};
