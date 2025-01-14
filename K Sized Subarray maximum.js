class Solution {
    maxOfSubarrays(arr, k) {
    let result = [];
    
    // Find the maximum for the first window of size k
    let currentMax = Math.max(...arr.slice(0, k)); // O(k)
    result.push(currentMax);
    
    for (let i = k; i < arr.length; i++) {

        if (arr[i - k] === currentMax) {
            // Recompute the max for the new window
            currentMax = Math.max(...arr.slice(i - k + 1, i + 1)); // O(k)
        } else {
            // Just compare the current max with the new element
            currentMax = Math.max(currentMax, arr[i]);
        }
        
        result.push(currentMax);
    }
    
    return result;
};

//Less optimised approach
var maxOfSubarrays = function(arr, k) {
    let result = [];
    
    // Loop through the array
    for (let i = 0; i <= arr.length - k; i++) {
        // Get the subarray of size k starting at index i
        let window = arr.slice(i, i + k);
        
        // Find the maximum element in the current window
        let maxInWindow = Math.max(...window);
        
        // Push the max value to the result array
        result.push(maxInWindow);
    }
    
    return result;
};
