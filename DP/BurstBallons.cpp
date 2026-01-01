class Solution {
public:
    vector<int> arr;
    int dp[303][303];
    
    int rec(int l, int r){
        if(l > r){
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for(int mid = l; mid <= r; mid++){
            ans = max(ans, rec(l, mid - 1) + rec(mid + 1, r) + arr[l-1] * arr[mid] * arr[r+1]);
        }
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n + 2);
        memset(dp, -1, sizeof(dp));
        
        arr[0] = 1;
        arr[n+1] = 1;
        for(int i = 0; i < n; i++){
            arr[i+1] = nums[i];
        }
        
        return rec(1, n);
    }
};
