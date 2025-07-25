class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t); 
    }
private:
    string process(const string& str){
        stack<char> stk;
        for(char ch : str){
            if(ch == '#') {
                if(!stk.empty()){
                    stk.pop();
                }
            } else {
                stk.push(ch);
            }
        }
        string result;
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
