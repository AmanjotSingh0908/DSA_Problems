//Beginner Approach
function missingNumber(n, arr) {
    for(let i=0; i<n-1; ++i){
        if(arr[i+1] == arr[i] + 1){
            continue;
        } else {
            return arr[i] + 1
        }
    }
}

//Approach with Sum of Natural numbers
function calculateSumOfNaturalNos(n){
    return (n*(n+1))/2;
}

function missingNumber(n, arr){
    const NaturalNumSum = calculateSumOfNaturalNos(n)
    let sum = 0;
    arr.sort((a,b)=>a-b)
    for (let index = 0; index < arr.length; index++) {
         sum += arr[index];
    }
    if(NaturalNumSum ==  sum){
        console.log("No Missing Number found")
    } else {
        return NaturalNumSum - sum
    }
}
n=7
arr = [2,3,4,6,5,7]
answer = missingNumber(n, arr)
console.log(answer)