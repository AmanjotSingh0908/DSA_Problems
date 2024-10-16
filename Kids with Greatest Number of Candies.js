var kidsWithCandies = function(candies, extraCandies) {
    // Find the largest number of candies without sorting
    let largest = Math.max(...candies);
    let result = [];
  
    for (let i = 0; i < candies.length; i++) {
        // Check if the current kid can have the most candies
        if (candies[i] + extraCandies >= largest) {
            result.push(true);
        } else {
            result.push(false);
        }
    }
    
    return result;
};
