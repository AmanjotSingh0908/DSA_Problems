
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        int currNo = 0;
        int ans = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                currNo = s[i] - '0';
                while (i + 1 < len && isdigit(s[i + 1])) {
                    currNo = currNo * 10 + (s[i + 1] - '0');
                    i++;
                }
                currNo = currNo * sign;
                ans += currNo;
                currNo = 0;
                sign = 1;
            } 
            else if (s[i] == '+') {
                sign = 1;
            } 
            else if (s[i] == '-') {
                sign = -1;
            } 
            else if (s[i] == '(') {
                st.push(ans);   // store result so far
                st.push(sign);  // store current sign
                ans = 0;
                sign = 1;
            } 
            else if (s[i] == ')') {
                int prevSign = st.top(); st.pop();
                ans = prevSign * ans;
                int prevAns = st.top(); st.pop();
                ans += prevAns;
            }
        }
        return ans;
    }
};


