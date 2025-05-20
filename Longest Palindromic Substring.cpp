class Solution {
public:
    string longestPalindrome(string s) { // O(N^2) using 2 Pointers.
        int n = s.length();
        int mx = 1;
        int ai = 0, aj = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i; // odd size
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    if (r - l + 1 > mx) {
                        mx = r - l + 1;
                        ai = l, aj = r;
                    }
                    else if (r - l + 1 == mx && l < ai) {
                        mx = r - l + 1;
                        ai = l, aj = r;
                    }
                    l--, r++;
                }
                else break;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1; // even size
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    if (r - l + 1 > mx) {
                        mx = r - l + 1;
                        ai = l, aj = r;
                    }
                    else if (r - l + 1 == mx && l < ai) {
                        mx = r - l + 1;
                        ai = l, aj = r;
                    }
                    l--, r++;
                }
                else break;
            }
        }
        return s.substr(ai, mx);
    }
};
