class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }

        int result = 0;
        while (num > 0) {
            result += num % 10; 
            num /= 10; // Remove last digit
        }

        while (result >= 10) {
            int temp = result;
            result = 0;
            while (temp > 0) {
                result += temp % 10;
                temp /= 10;
            }
        }

        return result;
    }
};
