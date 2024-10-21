// Approach combines elements of both Sliding Window and Kadane's Algorithm.
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(arr, k) {
    if (arr.length === 0 || arr.length < k) {
        return 0;
    }

    let maxi = -Infinity;
    let sum = 0;
    for(let index = 0; index < k; index++){
        sum += arr[index]
    }
    maxi = sum;
    for(let i = k; i<arr.length; i++){
        //slide window by removing an element and considering ith element
        sum = sum - arr[i - k] + arr[i];
        maxi = Math.max(maxi, sum)
    }
    return maxi/k;
};
