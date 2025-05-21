class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() < numRows)
            return s;

        std::vector<std::string> rows(numRows, "");
        int count = 0;
        bool direction = false;

        for (char c : s) {
            rows[count] += c;
            if (count == 0 || count == numRows - 1)
                direction = !direction;
            count += direction ? 1 : -1;
        }

        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};
