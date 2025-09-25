class Solution
{
    static const int MAXLOG = 20;
    int basis[MAXLOG];
    int sz;

    void insertVector(int mask)
    {
        for (int i = MAXLOG - 1; i >= 0; i--)
        {
            if ((mask & (1 << i)) == 0)
                continue; // ith bit is not set in num

            if (!basis[i])
            {
                basis[i] = mask;
                sz++;
                return;
            }

            mask = mask ^ basis[i];
        }
    }

    int queryMax()
    {
        int res = 0;
        for (int i = MAXLOG - 1; i >= 0; i--)
        {
            if (basis[i] != 0)
            {
                res = max(res, res ^ basis[i]);
            }
        }
        return res;
    }

public:
    int maxXorSubsequences(vector<int> &nums)
    {
        memset(basis, 0, sizeof(basis));
        sz = 0;

        for (int num : nums)
        {
            insertVector(num);
        }
        return queryMax();
    }
};
/*
https://codeforces.com/blog/entry/68953

Time Complexity: O(n × log(max_value)) - about O(n × 30) for this problem Space Complexity: O(log(max_value)) - about O(30) for the basis array
*/