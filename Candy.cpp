class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0) return 0;
    //left to right
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
    //right to left
        for(int i = n - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i + 1] + 1;
            }
        }

        long long sum = 0;
        for(int c : candies) sum += c;
        return (int) sum;
    }
};

// Left to right: ensure increasing sequences get +1 from left neighbor
// Right to left: fix places where rating[i] > rating[i+1]