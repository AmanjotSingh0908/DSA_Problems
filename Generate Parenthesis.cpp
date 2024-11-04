//Backtracking & Array

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void generateBrackets(string output, int n, int open, int close, vector<string>& result) {
        if (output.length() == 2 * n) {  
            result.push_back(output);
            return;
        }

        if (open < n) {
            generateBrackets(output + '(', n, open + 1, close, result);
        }

        if (close < open) {
            generateBrackets(output + ')', n, open, close + 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateBrackets("", n, 0, 0, result);
        return result;
    }
};
