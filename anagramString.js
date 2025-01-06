function anagram(s,t){
    let freqs = new Array(26)
    freqs.fill(0)
    
    let freqt = new Array(26)
    freqt.fill(0)
    
    if (s.length != t.length){
        return false;
    } else {
        for(let i=0; i<s.length; i++){
            console.log(++freqs[s[i].charCodeAt(0) - 'a'.charCodeAt(0)])
            console.log(--freqs[t[i].charCodeAt(0) - 'a'.charCodeAt(0)])
        }
        for(let j=0; j<26; j++){
            if(freqs[j] != 0){
                return false;
            }
        }
        return true
    }
}
s = 'aman'
t = 'mana'

result = anagram(s,t)
console.log(result)



//Another way
function areAnagrams(str1, str2) {
    str1 = str1.toLowerCase().replace(/[^a-z]/g, '');
    str2 = str2.toLowerCase().replace(/[^a-z]/g, '');

    if (str1.length !== str2.length) {
        return false;
    }

    const count1 = {};
    const count2 = {};

    for (let char of str1) {
        count1[char] = (count1[char] || 0) + 1;
    }

    for (let char of str2) {
        count2[char] = (count2[char] || 0) + 1;
    }

    for (let char in count1) {
        if (count1[char] !== count2[char]) {
            return false;
        }
    }

    return true;
}

console.log(areAnagrams("listen", "silent"));  
console.log(areAnagrams("hello", "world"));    
console.log(areAnagrams("A gentleman", "Elegant man"));
