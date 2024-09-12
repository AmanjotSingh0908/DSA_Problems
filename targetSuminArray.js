//target = 10
//return pair of numbers sum = 10....E.g. => [2,8] [3,7]
let arr = [10,2,7,8,3]
const target = 10

function findPairs(arr, target){
    let answer = [];
    for(let i = 0; i<arr.length; i++){
        if(arr[i] == target){
            answer.push([arr[i]])
        }
        for(let j = i+1; j<arr.length; j++){
            if(arr[i] + arr[j+1] == target){
                answer.push([arr[i], arr[j+1]]);
            }
        }
    }
    return answer;
}

result = findPairs(arr, target)
console.log(result)