class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i=0, result=0, sign=1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && s[i] == '+'){
            sign = 1;
            i++;
        } else if(i<n && s[i] == '-'){
            sign = -1;
            i++;
        }
        while(i<n && (s[i] - '0' >= 0 && s[i] - '0' <= 9)){
            int digit = s[i] - '0';
            if(result>INT_MAX/10 || (result == INT_MAX/10 && digit>INT_MAX%10)){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return result*sign;
    }
};