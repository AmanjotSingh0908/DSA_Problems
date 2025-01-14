/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(arr, k) {
    let maxSum = -Infinity;
    let currentSum = 0;
    let windowMap = new Map();

    for(let i=0; i<arr.length; i++){
        currentSum += arr[i];
        windowMap.set(arr[i], (windowMap.get(arr[i]) || 0) + 1);

        //Only when window size is k check if it has all distinct elements
        if(i >= k){
            let leftElement = arr[i - k];
            currentSum -= leftElement;
            windowMap.set(leftElement, windowMap.get(leftElement) - 1);
            if(windowMap.get(leftElement) === 0) {
                windowMap.delete(leftElement);
            }
        }

        if( i >= k - 1){
            if(windowMap.size === k){
                maxSum = Math.max(maxSum, currentSum);
            }
        }
    }

    return maxSum === -Infinity ? 0 : maxSum;
};
