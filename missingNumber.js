/**
 * @param {number[]} nums
 * @return {number}
 */
//O(nlogn)
var missingNumber = function(nums) {
    nums.sort((x,y) => x-y);
    for(let i =0; i<nums.length; i++){
        if(nums[i] !== i){
            return i;
        }
    }
    return nums.length
};

//O(n) using Gauss Formula
var missingNumber = function(nums) {
    let n = nums.length;
    let expectedSum = n * (n + 1) / 2;
    let actualSum = nums.reduce((sum, num) => sum + num, 0);
    return expectedSum - actualSum;
};


