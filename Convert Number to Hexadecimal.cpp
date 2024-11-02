class Solution {
public:
    std::string toHex(int num) {
        if (num == 0) return "0";

        std::string hex = "";
        unsigned int n = num; // Use unsigned to handle negative numbers correctly
        const char* hexDigits = "0123456789abcdef";

        while (n > 0) {
            hex = hexDigits[n % 16] + hex; // Get the last hex digit and prepend it
            n /= 16; // Divide by 16 to shift right
        }

        return hex;
    }
};
