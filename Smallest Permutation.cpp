#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    long long num;
    cin >> num;

    string strNum = to_string(num);

    // Sort digits in ascending order
    sort(strNum.begin(), strNum.end());

    // Handle leading zero if present
    if (strNum[0] == '0') {
        for (int i = 1; i < strNum.size(); i++) {
            if (strNum[i] != '0') {
                swap(strNum[0], strNum[i]);
                break;
            }
        }
    }

    // Print the smallest permutation
    cout << stoll(strNum) << "\n"; // Convert string to long long
    return 0;
}
