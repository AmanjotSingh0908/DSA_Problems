var countBits = function(n) {
    let result = new Array(n + 1).fill(0);

    for (let i = 1; i <= n; i++) {
        // If even, same number of 1s as i >> 1 (i divided by 2)
        // If odd, one more 1 than the previous number (i - 1)
        result[i] = result[i >> 1] + (i & 1);
    }

    return result;
};
