/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let occurences = new Array()
    let i = 0
    while(i <= nums.length){
    let x = nums[0]
        for(let i =0; i<nums.length; i++){
            if(x == nums[i]){
                occurences[x]++
            }
        }
        i++;
    }
    for(let i=0; i<occurences.length; i++){
        if(occurences[i] > (nums.length/2)){
            return nums[i]
        }
    }
};
