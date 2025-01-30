class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        std::unordered_set<std::string> distinctSubarrays;  
        int start = 0;  
        int divCount = 0;  
        
        for (int end = 0; end < nums.size(); ++end) {
            if (nums[end] % p == 0) {
                divCount++;
            }
            
            // Shrinking window if more than k divisible elements r there
            while (divCount > k) {
                if (nums[start] % p == 0) {
                    divCount--;
                }
                start++;
            }
            
            for (int i = start; i <= end; ++i) {
                std::stringstream ss;
                for (int j = i; j <= end; ++j) {
                    ss << nums[j] << ",";
                }
                distinctSubarrays.insert(ss.str());
            }
        }
        
        return distinctSubarrays.size();  
    }};
