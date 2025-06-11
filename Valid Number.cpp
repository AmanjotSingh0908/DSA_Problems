class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();

        // Trim leading spaces
        while (i < n && s[i] == ' ') i++;
        // If empty after trimming
        if (i == n) return false;

        // Check for optional sign
        if (s[i] == '+' || s[i] == '-') i++;

        bool isNumeric = false, isDot = false, isExp = false;

        while (i < n) {
            if (isdigit(s[i])) {
                isNumeric = true;
            } 
            else if (s[i] == '.') {
                if (isDot || isExp) return false;
                isDot = true;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (isExp || !isNumeric) return false;
                isExp = true;
                isNumeric = false; // There must be digits after exponent
                if (i + 1 < n && (s[i+1] == '+' || s[i+1] == '-')) i++; // Optional sign
            } 
            else if (s[i] == '+' || s[i] == '-') {
                // Signs are only valid at the beginning or just after 'e'/'E'
                if (s[i-1] != 'e' && s[i-1] != 'E') return false;
            } 
            else if (s[i] == ' ') {
                break; // Check tail spaces later
            } 
            else {
                return false;
            }
            i++;
        }

        // Trim trailing spaces
        while (i < n && s[i] == ' ') i++;

        return isNumeric && i == n;
    }
};
