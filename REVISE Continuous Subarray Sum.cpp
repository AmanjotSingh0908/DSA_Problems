class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixMap;
    prefixMap[0] = -1;  

    int prefixSum = 0; 
    for (int i = 0; i < nums.size(); ++i) {
        prefixSum += nums[i];
            
        int mod = (k == 0) ? prefixSum : prefixSum % k;

        if (mod < 0) {
            mod += k;
        }

        if (prefixMap.find(mod) != prefixMap.end()) {
            if (i - prefixMap[mod] > 1) {
                return true;
            }
        } else {
            prefixMap[mod] = i;
        }
    }
    return false;  
    }
};
