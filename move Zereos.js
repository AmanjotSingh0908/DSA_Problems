/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let n = nums.length;
    if((nums.length == 1) && (nums[0] == 0)){
        return nums;
    }

    let j = 0;
        for(let i = 0; i < nums.length; i++){
            if(nums[i]!=0){
                let temp = nums[i];
                nums[i] = 0;
                nums[j++] = temp;
            }
        }
    return nums;
};
