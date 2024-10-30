/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */

function intToBinary(n) {
    let binary = '';
    while (n > 0) {
        binary = (n % 2) + binary;  // Get the remainder (0 or 1) and prepend to binary string
        n = Math.floor(n / 2);      // Divide n by 2 to process the next bit
    }
    return binary || '0';           // Return '0' if n is 0
}

function padTo32Bits(binary) {
    while (binary.length < 32) {
        binary = '0' + binary;
    }
    return binary;
}

function reverseString(str) {
    let reversed = '';
    for (let i = str.length - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

function binaryToInt(binary) {
    let result = 0;
    for (let i = 0; i < binary.length; i++) {
        if (binary[i] === '1') {
            result += Math.pow(2, binary.length - 1 - i);  // Add the power of 2 at each '1' position
        }
    }
    return result;
}



var reverseBits = function(n) {
    let binary = intToBinary(n);           // Step 1: Convert integer to binary
    let paddedBinary = padTo32Bits(binary); // Step 2: Pad to 32 bits
    let reversedBinary = reverseString(paddedBinary); // Step 3: Reverse the binary string
    return binaryToInt(reversedBinary);     // Step 4: Convert reversed binary back to integer    
};
