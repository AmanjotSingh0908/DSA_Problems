/**
 * @param {string} s
 * @return {number}
 */
var maxProduct = function(s) {
    const n = s.length;
    let maxProduct = 0;

    const isPalindrome = (subseq) => {
        let left = 0, right = subseq.length - 1;
        while (left < right) {
            if (subseq[left] !== subseq[right]) return false;
            left++;
            right--;
        }
        return true;
    };

    const subsequences = [];
    for (let mask = 1; mask < (1 << n); mask++) {
        let subseq = '';
        for (let i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq += s[i];
            }
        }
        if (isPalindrome(subseq)) {
            subsequences.push([mask, subseq.length]); // Store bitmask and length
        }
    }

    const m = subsequences.length;
    for (let i = 0; i < m; i++) {
        for (let j = i + 1; j < m; j++) {
            const [mask1, len1] = subsequences[i];
            const [mask2, len2] = subsequences[j];
            if ((mask1 & mask2) === 0) {
                maxProduct = Math.max(maxProduct, len1 * len2);
            }
        }
    }

    return maxProduct;
};
