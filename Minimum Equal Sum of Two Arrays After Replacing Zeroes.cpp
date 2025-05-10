class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        for (int x : nums1) {
            if (x == 0) ++z1;
            else sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0) ++z2;
            else sum2 += x;
        }

        long long minSum1 = sum1 + z1;  // if every zero → 1
        long long minSum2 = sum2 + z2;
        if (minSum1 == minSum2) {
            // replace all zeros with 1 and return
            for (int &x : nums1) if (x == 0) x = 1;
            for (int &x : nums2) if (x == 0) x = 1;
            return minSum1;
        }

        // decide which side must “catch up”
        bool firstSmaller = minSum1 < minSum2;
        long long target = max(minSum1, minSum2);
        long long diff   = llabs(minSum1 - minSum2);

        if (firstSmaller && z1 == 0) return -1;  // no zeros to raise
        if (!firstSmaller && z2 == 0) return -1;

        // — now actually fill zeros —
        if (firstSmaller) {
            // nums1 is behind: fill one zero with (1 + diff), the rest with 1
            bool used = false;
            for (int &x : nums1) {
                if (x == 0) {
                    if (!used) {
                        x = 1 + diff;
                        used = true;
                    } else {
                        x = 1;
                    }
                }
            }
            // fill nums2 zeros with 1
            for (int &x : nums2) if (x == 0) x = 1;
        } else {
            // nums2 is behind
            bool used = false;
            for (int &x : nums2) {
                if (x == 0) {
                    if (!used) {
                        x = 1 + diff;
                        used = true;
                    } else {
                        x = 1;
                    }
                }
            }
            for (int &x : nums1) if (x == 0) x = 1;
        }

        // now both sums == target
        return target;
    }
};


//Can further be deduced to
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        for (int x : nums1) {
            if (x == 0) ++z1;
            else sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0) ++z2;
            else sum2 += x;
        }

        long long minSum1 = sum1 + z1;  // if every zero → 1
        long long minSum2 = sum2 + z2;
        if (minSum1 == minSum2) {
            return minSum1;
        }

        // decide which side must “catch up”
        bool firstSmaller = minSum1 < minSum2;
        long long target = max(minSum1, minSum2);

        if (firstSmaller && z1 == 0) return -1;  // no zeros to raise
        if (!firstSmaller && z2 == 0) return -1;

        return target;
    }
};
