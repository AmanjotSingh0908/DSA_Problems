//O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxElement = 0, maxDiff = 0;
        for (long num : nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return maxTriplet;
    }
};


//O(n^3)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long multiply = 0;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    multiply = (nums[i] - nums[j]) * nums[k];
                    ans = max(ans, multiply);
                }
            }
        }
        return ans;
    }
};
