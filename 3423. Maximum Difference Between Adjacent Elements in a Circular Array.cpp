class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) {
        int n = arr.size();
        int maxDiff = INT_MIN;
        for(int i = 0; i < n; i++){
            int currentDif = abs(arr[(i+1) % n] - arr[i]);
            maxDiff = max(currentDif, maxDiff);
        }
        return maxDiff;
    }
};
