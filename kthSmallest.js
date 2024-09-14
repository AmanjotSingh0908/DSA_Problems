// function kthSmallest(arr, k) {
//     arr.sort((a,b) => a-b);
//     return arr[k-1]       
// }

//Approach 2

//Using Counting Sort [ref. GFG]
function kthSmallest(Arr,k){
    let maxElement = Arr[0];
    for(let i=0; i<Arr.length; i++){
        if(Arr[i] > maxElement){
            maxElement = Arr[i]
        }
    }

    let frequencyArray = new Array(maxElement + 1).fill(0)
    for(let i=0; i<Arr.length; i++){
        frequencyArray[Arr[i]]++;
    }

    let count = 0;
    for(let i =0; i<=maxElement; i++){
        if(frequencyArray[i] !== 0){
            count += frequencyArray[i];
            if(count >= k){
                return i
            }
        }
    }
    return -1;
}

const arr = [4,4,8,2,1]
const k = 3
console.log(`${kthSmallest(arr,k)}`)

// Time Complexity: O(N + max_element), where max_element is the maximum element of the array.
// Auxiliary Space: O(max_element)