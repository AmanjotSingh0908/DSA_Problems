class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int p, q;
        int n = temperatures.size();
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};
//O(N^2) above solution

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); 
        stack<int> st; 

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                res[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }

        return res;
    }
};
//O(N) above solution
