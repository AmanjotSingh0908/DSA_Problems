class Solution {
public:
    
// Function to calculate  sum of  squares of digits of a number
int sumOfSquaresOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Function to determine if a number is a happy number
bool isHappy(int n) {
    unordered_set<int> seen; // Set to track numbers we've already encountered
    while (n != 1) {
        n = sumOfSquaresOfDigits(n); // Replace n with  sum of squares of digits
        if (seen.find(n) != seen.end()) { // If number has been seen before, it's a cycle
            return false;
        }
        seen.insert(n); // Mark this number as seen
    }
    return true; 
}
};
