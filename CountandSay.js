/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n === 1) return "1";
    if (n === 2) return "11";

    let s = "11";
    for (let i = 3; i <= n; i++) {
        let t = "";
        s += '&';
        let c = 1;

        for (let j = 1; j < s.length; j++) {
            if (s[j] !== s[j - 1]) {
                t += c.toString();
                t += s[j - 1];
                c = 1;
            } else {
                c++;
            }
        }
        s = t;
    }
    return s;
};
