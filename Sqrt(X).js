var mySqrt = function(x) {
    if (x == 0 || x == 1) return x;

    let start = 1, end = x;
    let result = 0;

    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2);

        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
};
