    let result = [];
    
    // Helper function for backtracking
    const backtrack = (start) => {
        // If the current index is at the end of the array, we've found a permutation
        if (start === nums.length) {
            result.push([...nums]); // Push a copy of the current permutation
            return;
        }
        
        // Loop through the array, swapping each element to the current position
        for (let i = start; i < nums.length; i++) {
            // Swap elements at indices start and i
            [nums[start], nums[i]] = [nums[i], nums[start]];
            
            // Recurse with the next index
            backtrack(start + 1);
            
            // Backtrack, undo the swap
            [nums[start], nums[i]] = [nums[i], nums[start]];
        }
    };
    
    // Start the backtracking process
    backtrack(0);
    
    return result;
