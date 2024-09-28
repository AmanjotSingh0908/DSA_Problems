/**
 * @param {string} s
 * @return {number}
 */
//Hard Leetcode Problem 
//https://leetcode.com/problems/longest-valid-parentheses/

var longestValidParentheses = function(s) {
    const stack = [-1];
    let answer = 0;

    for (let i = 0; i < s.length; i++) {
        let char = s[i];

        if (char === '(') {
            stack.push(i);
        } else {
            stack.pop();
            
            if (stack.length === 0) {
                stack.push(i);
            } else {
                answer = Math.max(answer, i - stack[stack.length - 1]);
            }
        }
    }

    return answer;
};
s = "(()()"
result = longestValidParentheses(s);
console.log(result)