    let result = [];
    

    const backtrack = (start) => {
    
        if (start === nums.length) {
            result.push([...nums]); // Push a copy of the current permutation
            return;
        }
        
        
        for (let i = start; i < nums.length; i++) {
   
            [nums[start], nums[i]] = [nums[i], nums[start]];
            
            // Recurse with the next index
            backtrack(start + 1);
            
            // Backtrack, undo the swap
            [nums[start], nums[i]] = [nums[i], nums[start]];
        }
    };
    
    backtrack(0);
    
    return result;
