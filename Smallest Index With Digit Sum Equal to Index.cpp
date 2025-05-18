class Solution {
public:
    int digitSum(int digit){
        int sum = 0;
        while(digit > 0){
            int temp = digit % 10;
            sum += temp;
            digit = digit/10;
        }
        return sum;
    }
    
    int smallestIndex(vector<int>& nums) {
        // int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(digitSum(nums[i]) == i){
               return i;
            }
        }
        return -1;
    }
};
