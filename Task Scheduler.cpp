class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        
        // Count frequency of each task
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        
        // Find max frequency and count of max frequency tasks
        int maxFreq = *max_element(count.begin(), count.end());
        int maxFreqCount = 0;
        for (int freq : count) {
            if (freq == maxFreq) maxFreqCount++;
        }
        
        // Formula: max(tasks.size(), (maxFreq-1)*(n+1) + maxFreqCount)
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxFreqCount);
    }
};
