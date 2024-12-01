/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function(arr) {
    for(let k = 0; k < arr.length; k++){
        for(let p = k; p < arr.length; p++){
            if(k != p && (arr[k] == 2 * arr[p] || arr[p] == 2 * arr[k])){
                return true
            }
        }
    }
    return false
};
