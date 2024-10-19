function hammingWeight(n) {
  let binary = n.toString(2);
  
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
