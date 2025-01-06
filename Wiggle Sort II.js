var wiggleSort = function(nums) {
    const n = nums.length;
    nums.sort((a, b) => a - b);

    const sorted = [...nums];

    let left = Math.floor((n - 1) / 2); 
    let right = n - 1; // Last element

    for (let i = 0; i < n; i++) {
        if (i % 2 === 0) {
            nums[i] = sorted[left--];
        } else {
            nums[i] = sorted[right--];
        }
    }
};
