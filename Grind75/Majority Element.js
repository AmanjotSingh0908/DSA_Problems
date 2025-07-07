/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let occurrences = {};
    let i =0;
    while (i < nums.length){
        let x = nums[i];

        if(occurrences[x] == null){
            occurrences[x] = 0;
        }
        occurrences[x]++;

        i++;
    }

    for(let key in occurrences) {
        if (occurrences[key] > (nums.length / 2)) {
            return parseInt(key);
        }
    }
};
