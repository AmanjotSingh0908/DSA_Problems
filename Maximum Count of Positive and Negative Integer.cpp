class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0;
        int posCount = 0;
        int ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negCount++;
            } else if(nums[i] > 0){
                posCount++;
            }
        }
        return max(negCount, posCount);
    }
};
