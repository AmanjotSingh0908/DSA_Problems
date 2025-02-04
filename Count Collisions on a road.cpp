REVISE
/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function(directions) {
    let stack = [];
    let collisions = 0;
    
    for (let car of directions) {
        if (car === 'R') {
            stack.push(car);
        } else if (car === 'S') {
            while (stack.length > 0 && stack[stack.length - 1] === 'R') {
                collisions++;  
                stack.pop();
            }
            stack.push('S');  
        } else if (car === 'L') {
            if (stack.length > 0 && stack[stack.length - 1] === 'R') {
                collisions += 2; 
                stack.pop(); 
                
                // Process remaining 'R' cars
                while (stack.length > 0 && stack[stack.length - 1] === 'R') {
                    collisions++;
                    stack.pop();
                }
                stack.push('S');  
            } else if (stack.length > 0 && stack[stack.length - 1] === 'S') {
                collisions++; 
            } else {
                stack.push('L'); 
            }
        }
    }
    
    return collisions;
};
