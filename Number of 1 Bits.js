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
