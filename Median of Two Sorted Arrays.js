/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function max(a, b) {
    return a > b ? a : b;
}

function min(a, b) {
    return a < b ? a : b;
}

var findMedianSortedArrays = function(nums1, nums2) {
    let n1 = nums1.length;
    let n2 = nums2.length;
    
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    let low = 0;
    let high = n1;
    let halfLen = Math.floor((n1 + n2 + 1) / 2);

    while (low <= high) {
        let mid1 = Math.floor((low + high) / 2);
        let mid2 = halfLen - mid1;

        let l1 = (mid1 > 0) ? nums1[mid1 - 1] : -Infinity;
        let l2 = (mid2 > 0) ? nums2[mid2 - 1] : -Infinity;
        let r1 = (mid1 < n1) ? nums1[mid1] : Infinity;
        let r2 = (mid2 < n2) ? nums2[mid2] : Infinity;

        if (l1 <= r2 && l2 <= r1) {
            // If the total length is odd
            if ((n1 + n2) % 2 === 1) {
                return max(l1, l2);
            } else {
                // If the total length is even
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    
    return 0; 
};
