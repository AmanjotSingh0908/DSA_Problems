function hashing(word){
    let hashedword =""
    
    //split
    const splittedWord = word.split("")
    //move each alphabet by word length
    splittedWord.forEach(element => {
        const res = element.charCodeAt(0) + word.length;
        hashedword += String.fromCharCode(res)
    });
    //join to form new word

    return hashedword;
}

const result = hashing("Aman")
console.log(result)
