#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Solution {
private:
    std::vector<std::vector<int>> rects;
    std::vector<int> prefixSum;
    int totalArea;

public:
    Solution(std::vector<std::vector<int>>& rects) {
        this->rects = rects;
        totalArea = 0;

        // Calculate prefix sum array
        for (int i = 0; i < rects.size(); i++) {
            int width = rects[i][2] - rects[i][0] + 1;
            int height = rects[i][3] - rects[i][1] + 1;
            totalArea += width * height;
            prefixSum.push_back(totalArea);
        }

        // Initialize random number generator
        std::srand(std::time(0));
    }

    std::vector<int> pick() {
        // Generate a random number in the range [0, totalArea-1]
        int randPoint = std::rand() % totalArea;

        // Binary search to find which rectangle contains the random point
        int left = 0, right = prefixSum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] > randPoint) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int rectIdx = left;
        std::vector<int>& rect = rects[rectIdx];

        // Randomly select a point within the chosen rectangle
        int x = rect[0] + std::rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + std::rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * std::vector<int> param_1 = obj->pick();
 */
