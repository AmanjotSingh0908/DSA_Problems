class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = (nums[i] % 2 == 0) ? 0 : 1;
        }

        int n = nums.size();
        for(int pass = 0; pass < n - 1; pass++) { //Bubble sort with repeated passes
            for(int i = 0; i < n - 1; i++) {
                if(nums[i] > nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                }
            }
        }

        return nums;
    }
};
