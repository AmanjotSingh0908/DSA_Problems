/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle.length > haystack.length){
        return -1
    }
    if (needle.length  == 0) {
        return 0;
    }

    let index = haystack.indexOf(needle);
    return index;
};
