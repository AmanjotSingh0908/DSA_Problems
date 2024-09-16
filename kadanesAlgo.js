arr = [-2,-3,4,-1,-2,1,5,-3]

//helper function
function max(a,b){
    if(a>b){
        return a
    } else {
        return b
    }
}

//Approach 1 | TC => O(N^3), SC => O(1)
function findsubArraySum(arr){
    let maxi = -Infinity
    for(let i =0; i< arr.length; i++){
        for(let j=i; j<arr.length; j++){
            let sum = 0
            for(let k = i; k<j; k++){
                sum += arr[k];
            }
            maxi = max(sum, maxi)
        }
    }
    return maxi
}

//Approach 2 | TC => O(N^2) SC => O(1)
function findsubArraySum(arr){
    let maxi = -Infinity
    for(let i =0; i< arr.length; i++){
        let sum = 0
        for(let j=i; j<arr.length; j++){
            sum += arr[j];
            maxi = max(sum, maxi)
        }
    }
    return maxi
}

//Appraoch 3 | Kadane's (Algo [Optimal] => TC - O(N)
function findsubArraySum(arr){
    let maxi = -Infinity
    let sum = 0
    for (let index = 0; index < arr.length; index++) {
        sum += arr[index]
        if(sum > maxi){
            maxi = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}


const answer = findsubArraySum(arr)
console.log(answer)