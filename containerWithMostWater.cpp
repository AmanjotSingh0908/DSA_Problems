//Brute Force
// TC - O(N^2)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int w;
                int ht;
                int area;
                w = j - i;
                ht = min(height[i], height[j]);
                area = w * ht;
                maxWater = max(maxWater, area);
            }
        }
        return maxWater;
    }
};

//Optimal - Two Pointer Approach

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp=0;
        int n = height.size();
        int rp = n-1;
        while(lp < rp){
            int w,ht, currentWater;
            w = rp-lp;
            ht = min(height[lp], height[rp]);
            currentWater = w * ht;
            maxWater = max(maxWater, currentWater);
            
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};
