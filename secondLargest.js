function print2largest(arr) {
    if (arr.length < 2) {
        return -1; 
    }

    let first = -Infinity, second = -Infinity;

    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second === -Infinity ? -1 : second; // Return -1 if no second largest element is found
}
