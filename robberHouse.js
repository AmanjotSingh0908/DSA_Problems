function rob(nums){

    if(nums.length === 0) return 0;
    if(nums.length === 1) return nums[0];

    let prev1 = nums[0];
    let prev2 = 0;
    
    for(let i=1; i<nums.length; i++){
        let current = Math.max(prev1, nums[i] + prev2)
        prev2 = prev1
        prev1 = current
    }

    return prev1
}
nums = [9,1,1,7,1]
result = rob(nums)
console.log(result)