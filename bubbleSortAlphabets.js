Alphabets = ['a','b','d','e','f','c','h','g']
// function bubbleSort(arr){
//     const length = arr.length;
//     for(let i = 0; i < length - 1; i++){
//         for(let j=0; j<length-1; j++){
//             if(arr[j] > arr[j+1]){
//                 let temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     return arr;
// }

// console.log(bubbleSort(Alphabets))w
Array.prototype.bubbleSort = function(arr){
    arr = this;
    const length = arr.length;
    for(let i = 0; i < length - 1; i++){
        for(let j=0; j<length-1; j++){
            if(arr[j] > arr[j+1]){
                let temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

let result = Alphabets.bubbleSort(Alphabets);
console.log(result)