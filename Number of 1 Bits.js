function hammingWeight(n) {
  // Convert number to its binary representation
  let binary = n.toString(2);
  
  // Split the binary string into an array and count the number of '1's
  let count = 0;
  
  for (let bit of binary) {
    if (bit === '1') {
      count++;
    }
  }
  
  return count;
}

//Approach 2
function hammingWeight(n) {
  let count = 0;
  
  while (n !== 0) {
    // n & (n - 1) flips the least significant set bit to 0
    n &= (n - 1);
    count++;
  }
  
  return count;
}
