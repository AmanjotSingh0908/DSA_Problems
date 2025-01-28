class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // Step 1: Sort the access times based on the time
        sort(access_times.begin(), access_times.end(), compareByTime);

        // Step 2: Create a map to store the access times for each employee
        unordered_map<string, vector<int>> employeeAccessTimes;
        
        for (int i = 0; i < access_times.size(); ++i) {
            string employee = access_times[i][0]; // Employee name
            string time = access_times[i][1]; // Access time in "HHMM" format
            
            // Convert time "HHMM" to total minutes since midnight
            int hours = (time[0] - '0') * 10 + (time[1] - '0');
            int minutes = (time[2] - '0') * 10 + (time[3] - '0');
            int totalMinutes = hours * 60 + minutes;
            
            // Store the total minutes for the employee
            employeeAccessTimes[employee].push_back(totalMinutes);
        }

        // Step 3: Find employees with 3 or more accesses within any 1-hour period
        vector<string> result;

        // Iterate through each employee's access times
        for (unordered_map<string, vector<int>>::iterator it = employeeAccessTimes.begin(); it != employeeAccessTimes.end(); ++it) {
            string employee = it->first;
            vector<int> times = it->second;
            
            // Check every access time for this employee
            for (int i = 0; i < times.size(); ++i) {
                int windowStart = times[i];  // Start of the current 1-hour window
                int windowEnd = windowStart + 59; // End of the 1-hour window

                int count = 0;
                // Count how many access times fall within the 1-hour window
                for (int j = i; j < times.size() && times[j] <= windowEnd; ++j) {
                    count++;
                }

                // If the employee has 3 or more accesses in this window, add them to the result
                if (count >= 3) {
                    result.push_back(employee);
                    break; // No need to check further once we find 3 accesses for this employee
                }
            }
        }

        return result;
    }

private:
    // Helper function to sort access times based on time in HHMM format
    static bool compareByTime(const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
    }
};
