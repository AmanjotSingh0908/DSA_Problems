class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> results;

        // Loop through possible hour values (0 to 11)
        for (int hour = 0; hour < 12; ++hour) {
            // Loop through possible minute values (0 to 59)
            for (int minute = 0; minute < 60; ++minute) {
                // Count the number of 1s in the binary representation of hour and minute
                if (countSetBits(hour) + countSetBits(minute) == turnedOn) {
                    // Format the time and add to results
                    results.push_back(std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute));
                }
            }
        }

        return results;
    }

private:
    int countSetBits(int num) {
        return std::bitset<6>(num).count(); // Max bits needed is 6 for minutes
    }
};
