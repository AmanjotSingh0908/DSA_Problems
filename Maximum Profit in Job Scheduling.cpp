class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(jobs.begin(), jobs.end());

        // Prepare only startTimes for binary search
        vector<int> starts;
        for (auto& job : jobs) starts.push_back(get<0>(job));
        
        vector<int> memo(n, -1);

        function<int(int)> dfs = [&](int i) {
            if (i == n) return 0;
            if (memo[i] != -1) return memo[i];

            // Option 1: skip current job
            int res = dfs(i + 1);

            // Option 2: take current job, find next job starting >= current end time
            int nextEnd = get<1>(jobs[i]);
            int j = lower_bound(starts.begin(), starts.end(), nextEnd) - starts.begin();

            res = max(res, get<2>(jobs[i]) + dfs(j));
            memo[i] = res;
            return res;
        };

        return dfs(0);
    }
};
