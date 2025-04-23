class Solution {
public:
    int digitSum(int num){
        int ans = 0;
        while(num) {
            ans += (num%10);
            num /= 10;
        }
        return ans;
    }

    int countLargestGroup(int n) {
        int maxSize = 0;
        unordered_map<int, int>freq;
        for(int i = 1; i <= n; i++){
            int digisum = digitSum(i);
            freq[digisum]++;
            maxSize = max(maxSize, freq[digisum]);
        }
        int result = 0;
        for(auto it:freq){
            if(it.second == maxSize) result++;
        }
        return result;
    }
};
