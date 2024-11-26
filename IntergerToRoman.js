var intToRoman = function(num) {
    let intCode = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    let code = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
    let sb = [];
    
    for (let i = 0; i < intCode.length; i++) {
        while (num >= intCode[i]) {
            sb.push(code[i]);
            num -= intCode[i];
        }
    }
    
    return sb.join('');
};
