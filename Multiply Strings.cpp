/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
//Do not try by converting strings to number directlt becoz of Precision issues over INT_SAFE_MAX

var multiply = function(num1, num2) {
    if(num1 == "0" || num2 == "0") return "0";
    const result = Array(num1.length + num2.length).fill(0);
    for(let i = num1.length - 1; i >= 0; i--){
        for(let j = num2.length - 1; j >= 0; j--){
            const mul = (num1[i] - '0') * (num2[j] - '0')
            const sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += Math.floor(sum / 10);
        }
    }

    while(result[0] === 0){
        result.shift();
    }

    return result.join('');
};
