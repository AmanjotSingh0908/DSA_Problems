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