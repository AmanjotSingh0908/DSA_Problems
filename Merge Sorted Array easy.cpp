// Compare elements from the end of both arrays.
// Place the larger one at the back (nums1[p]).
// Move the corresponding pointer backward.
// If nums2 still has leftover elements, copy them into nums1 (no need to handle leftover from nums1, since they’re already in place).

/*Since nums1 has enough space to hold both arrays, you should merge from the back to avoid overwriting useful elements in nums1.*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        //If nums2 still has elements left, copy them all
        while(p2 >= 0){
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }

    }
};
