arr = [1,2,4,6]

function findMissingNumber(arr){
    let start = arr[0];
    let result = [];
    const length = arr.length;

    for (let index = 0; index < arr.length; index++) {
        while(start < arr[index]){
            result.push(start);
            start++;
        }
        start++;
    }
    return result;
}

let answer =findMissingNumber(arr);
console.log(answer)