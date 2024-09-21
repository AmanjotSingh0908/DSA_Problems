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

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.


// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.