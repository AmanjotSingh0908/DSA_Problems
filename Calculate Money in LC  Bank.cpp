class Solution {
public:
    int totalMoney(int n) {
    long long w = n / 7, r = n % 7;
    long long full = 7 * w * (w + 7) / 2;                 // sum over full weeks
    long long rem  = r * (2 * (w + 1) + (r - 1)) / 2;     // sum of remaining days
    return (int)(full + rem);

    }
};
