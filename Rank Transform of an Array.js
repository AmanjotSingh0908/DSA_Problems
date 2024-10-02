/**
 * @param {number[]} arr
 * @return {number[]}
 */
//Optimised Approach
var arrayRankTransform = function(arr) {
    let temp = [...arr].sort((x, y) => x - y);
    
    let rankMap = {};
    let rank = 1; 
    
    for (let i = 0; i < temp.length; i++) {
        if (rankMap[temp[i]] === undefined) {
            rankMap[temp[i]] = rank;
            rank++;  
        }
    }
    for (let i = 0; i < arr.length; i++) {
        arr[i] = rankMap[arr[i]];
    }
    
    return arr;
};


//Approach 2
var arrayRankTransform = function(arr) {
    let temp = [...arr].sort((x, y) => x - y);
    let rankMap = {};
    for (let i = 0; i < temp.length; i++) {
        if (rankMap[temp[i]] === undefined) {
            rankMap[temp[i]] = Object.keys(rankMap).length + 1;
        }
    }
    for (let i = 0; i < arr.length; i++) {
        arr[i] = rankMap[arr[i]];
    }
    
    return arr;
};
