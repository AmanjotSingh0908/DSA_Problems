class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        // Calculate initial penalty if we close at hour 0
        // (all 'Y's after closing contribute to penalty)
        int penalty = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') penalty++;
        }
        
        int minPenalty = penalty;
        int bestHour = 0;
        
        // Try closing at each hour from 1 to n
        for(int j = 0; j < n; j++) {
            // If we keep shop open one more hour:
            // - If customers[j] == 'N': penalty increases (shop open, no customer)
            // - If customers[j] == 'Y': penalty decreases (we served the customer)
            if(customers[j] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }
            
            // Update minimum penalty and best hour
            if(penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j + 1;
            }
        }
        
        return bestHour;
    }
};
