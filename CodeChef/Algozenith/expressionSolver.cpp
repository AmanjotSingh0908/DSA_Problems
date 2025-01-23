#include <iostream>
#include <string>
using namespace std;

void evaluateSide(const string &side, int &xCoefficient, long long &constant) {
    int sign = 1;
    long long currentNumber = 0;
    bool hasNumber = false;

    for (size_t i = 0; i <= side.length(); i++) {
        if (i < side.length() && isdigit(side[i])) {
            currentNumber = currentNumber * 10 + (side[i] - '0');
            hasNumber = true;
        } else if (i < side.length() && side[i] == 'X') {
            xCoefficient += sign * (hasNumber ? currentNumber : 1);
            currentNumber = 0;
            hasNumber = false;
        } else if (i == side.length() || side[i] == '+' || side[i] == '-') {
            if (hasNumber) {
                constant += sign * currentNumber;
                currentNumber = 0;
                hasNumber = false;
            }
            if (i < side.length()) {
                sign = (side[i] == '+') ? 1 : -1;
            }
        }
    }
}

int main() {
    string expression;
    cin >> expression;

    size_t equalPos = expression.find('=');
    string leftPart = expression.substr(0, equalPos);
    string rightPart = expression.substr(equalPos + 1);

    int leftXCoefficient = 0, rightXCoefficient = 0;
    long long leftConstant = 0, rightConstant = 0;

    evaluateSide(leftPart, leftXCoefficient, leftConstant);
    evaluateSide(rightPart, rightXCoefficient, rightConstant);

    int totalXCoefficient = leftXCoefficient - rightXCoefficient;
    long long totalConstant = rightConstant - leftConstant;

    cout << totalConstant / totalXCoefficient << endl;

    return 0;
}
