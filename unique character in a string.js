var firstUniqChar = function(s) {
    s.toLowerCase()
//frequency array for 26 lowercase letters
let freq = new Array(26).fill(0);
//Populate frequency array
for(let c of s){
    freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
}
//
for(let i=0; i < s.length; ++i){
    if(freq[s[i].charCodeAt(0) - 'a'.charCodeAt(0)] == 1){
        return i
    }
}
return -1;
};

str = "lovelotus"
answer = firstUniqChar(str)
console.log(answer)