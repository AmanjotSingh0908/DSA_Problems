class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int g : gas) totalGas += g;
        for(int c : cost) totalCost += c;
        if(totalGas < totalCost) return -1;

        int total = 0, res = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};

//Tricky part was to identify it that it was a greedy problem and its approach
