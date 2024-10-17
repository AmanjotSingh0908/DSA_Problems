//Bitwise Operators
class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is negative
        if (n < 0) {
            // Special case for INT_MIN
            if (n == INT_MIN) {
                x = 1 / x; // Invert the base
                n = -(n + 1); // Adjust n to be positive
                return x * myPow(x, n); // Handle x^(-n-1) and return final result
            }
            x = 1 / x; // Invert the base
            n = -n;    // Make n positive
        }

        double result = 1.0;
        while (n > 0) {
            if (n & 1) {  // If n is odd
                result *= x;
            }
            x *= x;       // Square the base
            n >>= 1;      // Divide n by 2
        }

        return result;
    }
};
