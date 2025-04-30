class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int countnums= 0;
        int ans = 0;
        int n = nums.size();
        for(int i =0; i< n; i++){
            int num = nums[i];
            countnums = 0;
            while(num > 0){
            num /= 10;
            countnums++;
            }
            if(countnums % 2 == 0){
                ans++;
            }
        }
        return ans;
    };
};
