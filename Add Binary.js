/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let result = [];
    let carry = 0;
    let i = a.length - 1;
    let j = b.length - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        let sum = carry;
        
        // Add the current bit from a if available
        if (i >= 0) {
            sum += a[i] === '1' ? 1 : 0;
            i--;
        }
        
        // Add the current bit from b if available
        if (j >= 0) {
            sum += b[j] === '1' ? 1 : 0;
            j--;
        }
        
        result.push(sum % 2);
        carry = Math.floor(sum / 2);
    }
    return result.reverse().join('');
};
