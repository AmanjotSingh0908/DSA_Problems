class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = 0;
        int Bottomans = 0;
        int Topans = 0;
        int n = tops.size();
        map<int,int> freq{};
        map<int,int> freq2{};
        int maxFreq = 0;
        int maxFreq2 = 0;
        int repeatElement = tops[0];
        int repeatElement2 = bottoms[0];
        for(int i = 0; i < n; i++){
            freq[tops[i]]++;
            if(freq[tops[i]] > maxFreq) {
                maxFreq = freq[tops[i]];
                repeatElement = tops[i];
            }
        }
        for(int i = 0; i < n; i++){
            freq2[bottoms[i]]++;
            if(freq2[bottoms[i]] > maxFreq2) {
                maxFreq2 = freq2[bottoms[i]];
                repeatElement2 = bottoms[i];
            }
        }
        // Check if we can make the whole row equal to repeatElement (from tops)
        bool canMakeTop = true;
        bool canMakeBottom = true;
        for(int j = 0; j < n; j++){
            if(tops[j] != repeatElement && bottoms[j] != repeatElement) {
                canMakeTop = false;
                break;
            }
        }
        if (canMakeTop) {
            for(int j = 0; j < n; j++){
                if(bottoms[j] == repeatElement && tops[j] != repeatElement){
                    Bottomans++;
                }
            }
        } else {
            Bottomans = INT_MAX;
        }

        for(int j = 0; j < n; j++){
            if(tops[j] != repeatElement2 && bottoms[j] != repeatElement2) {
                canMakeBottom = false;
                break;
            }
        }
        if (canMakeBottom) {
            for(int j = 0; j < n; j++){
                if(tops[j] == repeatElement2 && bottoms[j] != repeatElement2){
                    Topans++;
                }
            }
        } else {
            Topans = INT_MAX;
        }

        int result = min(Bottomans, Topans);
        return result == INT_MAX ? -1 : result;
    }
};
