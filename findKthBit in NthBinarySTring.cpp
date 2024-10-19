#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to recursively find the kth bit
        return helper(n, k) + '0';  // Convert result (0 or 1) to char '0' or '1'
    }
    
private:
    int helper(int n, int k) {
        if (n == 1) { 
            return 0;
        }
        
        int mid = (1 << (n - 1));  
        if (k == mid) {
            return 1;  // The middle bit is always "1"
        } else if (k < mid) {
            return helper(n - 1, k);  // Look in the first half
        } else {
            // Look in the second half, reverse and invert the corresponding position
            return 1 - helper(n - 1, mid - (k - mid));
        }
    }
};

int main() {
    Solution solution;
    // Example 1:
    cout << solution.findKthBit(3, 1) << endl;  // Output: "0"
    
    // Example 2:
    cout << solution.findKthBit(4, 11) << endl;  // Output: "1"
    
    return 0;
}
