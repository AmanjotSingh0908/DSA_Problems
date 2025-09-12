/*
For each asteroid:
- Push operation: happens at most once per asteroid → O(n) total
- Pop operation: happens at most once per asteroid → O(n) total
- Total operations: O(n) + O(n) = O(n)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &a : asteroids){
            while(!st.empty() && a < 0 && st.top() > 0){
                if(st.top() < -a){
                    st.pop();
                } else if(st.top() == -a){
                    st.pop();
                    a = 0;
                } else {
                    a = 0;
                }
            }
            if(a != 0) st.push(a);
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};