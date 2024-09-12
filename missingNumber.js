//With single number
const arr = [1,2,4,5]
start = arr[0];


function findMissingNumber(arr, start){
        for(let i =0; i<arr.length; i++){
                //increment start on each iteration and check the missing number
                        if(arr[i]==start){
                                start++;
                                continue;
                            } else {
                                    console.log(start);
                                    break;
                                }
                    }
                }

findMissingNumber(arr, start);

Array.prototype.findMissingNumber = function (arr) {
    arr = this;
    let start = arr[0];
    let result;
    for(let i =0; i<arr.length; i++){
        //increment start on each iteration and check the missing number
                if(arr[i]==start){
                    start++;
                    continue;
                } else {
                    result = start;
                    break;
                }
    }
    return result;
}

console.log(arr.findMissingNumber(arr))

