class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;

        for(int num : nums){
            while(!st.empty() && st.top() > num){
                int merged = st.top();
                st.pop();
                num = max(num, merged);
            }
            st.push(num);
        }

        return st.size();
    }
};
