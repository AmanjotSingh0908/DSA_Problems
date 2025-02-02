class Solution {
public:
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void binarySearch(long l, long h, int divisor1, int divisor2, long lcm, long &ans, int c1, int c2) {
        while (l <= h) {
            long m = l + (h - l) / 2;

            long a = m - (m / divisor1);
            long b = m - (m / divisor2);
            long c = m - (m / divisor1) - (m / divisor2) + (m / lcm);

            if (a >= c1 && b >= c2 && (a + b - c) >= (c1 + c2)) {
                ans = m;
                h = m - 1; 
            } else {
                l = m + 1;
            }
        }
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g = gcd(max(divisor1, divisor2), min(divisor1, divisor2));
        long lcm = (divisor1 / g) * divisor2; // Avoids overflow

        long ans = 1e9; 
        binarySearch(2, 2e9, divisor1, divisor2, lcm, ans, uniqueCnt1, uniqueCnt2);
        return int(ans);
    }
};
