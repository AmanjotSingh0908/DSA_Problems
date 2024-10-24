/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    let vowels = ['a','e','i','o','u','A','E','I','O','U'];
    let sArray = s.split('');
    let occurence = [];

    for(let i=0; i<sArray.length; i++){
        if(vowels.includes(sArray[i])){
            occurence.push(i);
        }
    }

    let left = 0;
    let right = occurence.length-1;
    while(left<right){
        let temp = sArray[occurence[left]];
        sArray[occurence[left]] = sArray[occurence[right]];
        sArray[occurence[right]] = temp;
        left++;
        right--;
    }
    return sArray.join('');
};
