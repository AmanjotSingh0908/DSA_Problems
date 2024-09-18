function minJumps(arr) {
    let jumps = 0;
    let current = 0;
    let farthest = 0;

    for (let i = 0; i < arr.length - 1; i++) {
        farthest = Math.max(farthest, arr[i] + i); 
        
        if (i == current) { 
            current = farthest; 
            jumps++; 

            if (current >= arr.length - 1) {
                break;
            }
        }
    }

    return current >= arr.length - 1 ? jumps : -1; 
    // Return -1 if the end is unreachable

}

const arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
answer = minJumps(arr)
console.log(answer)