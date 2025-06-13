class Solution {
public:
    int p;  // Store 'p' as class member for access in isValid
    vector<int> nums;  // Store 'nums' as a class member

    bool isValid(int threshold) {
        int cnt = 0;
        int i = 0;
        while (i < nums.size() - 1) {
            if (abs(nums[i] - nums[i + 1]) <= threshold) {
                cnt++;
                i += 2;  // Skip next element 
            } else {
                i += 1;
            }
        }
        return cnt >= p;
    }

    int minimizeMax(vector<int>& inputNums, int inputP) {
        nums = inputNums;
        p = inputP;

        sort(nums.begin(), nums.end());  // Correct sorting

        int l = 0, r = 1e9;
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
