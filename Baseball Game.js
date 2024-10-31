/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function(operations) {
    let result = [];

    for (let i = 0; i < operations.length; i++) {
        if (operations[i] === '+') {
            if (result.length >= 2) {
                let sum = result[result.length - 1] + result[result.length - 2];
                result.push(sum);
            }
        } else if (operations[i] === 'D') {
            if (result.length >= 1) {
                result.push(result[result.length - 1] * 2);
            }
        } else if (operations[i] === 'C') {
            result.pop();
        } else {
            result.push(Number(operations[i]));
        }
    }

    // Sum up all the elements in result
    return result.length > 0 ? result.reduce((acc, curr) => acc + curr, 0) : 0;
};
