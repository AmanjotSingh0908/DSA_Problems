function kthSmallest(arr, k) {
    arr.sort((a,b) => a-b);
    return arr[k-1]       
}

//I need another approach without sorting it 