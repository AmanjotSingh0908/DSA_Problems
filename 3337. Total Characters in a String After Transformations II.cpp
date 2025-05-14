//Uses Matrix Exponentiation

class Solution {
public:
    static const int mod = 1e9 + 7;
    static const int sz = 26;

    struct Mat {
        long long m[26][26];
        Mat() {
            for (int i = 0; i < sz; ++i)
                for (int j = 0; j < sz; ++j)
                    m[i][j] = 0;
        }

        void identity() {
            for (int i = 0; i < sz; ++i)
                m[i][i] = 1;
        }

        Mat operator* (const Mat& other) const {    //Operator Overloading, Check CPCodes Repo to learn more
            Mat res;
            for (int i = 0; i < sz; ++i)
                for (int j = 0; j < sz; ++j)
                    for (int k = 0; k < sz; ++k)
                        res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % mod;
            return res;
        }
    };

    Mat power(Mat base, int t) {
        Mat res;
        res.identity();
        while (t > 0) {
            if (t & 1) res = res * base;
            base = base * base;
            t >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Step 1: Build transformation matrix
        Mat T;
        for (int i = 0; i < 26; ++i) {
            int count = nums[i];
            for (int j = 1; j <= count; ++j) {
                int to = (i + j) % 26;
                T.m[i][to] = (T.m[i][to] + 1) % mod;
            }
        }

        // Step 2: Raise matrix to power t
        Mat Tt = power(T, t);

        // Step 3: Initialize frequency vector of starting string
        long long cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Step 4: Multiply matrix Tt with cnt vector
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            long long sum = 0;
            for (int j = 0; j < 26; ++j) {
                sum = (sum + Tt.m[j][i] * cnt[j]) % mod;
            }
            result = (result + sum) % mod;
        }

        return result;
    }
};
