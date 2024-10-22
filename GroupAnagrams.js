/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    if(strs.length === 0){
        return [[""]]
    } else if (strs.length === 1) {
        return [strs]
    } else {
      let anagramMap = {};

     for (let str of strs) {
        // Sort string to get the key for the anagram group
        let sortedStr = str.split('').sort().join('');
        
        // If the sorted string is not a key in the map, add it
        if (!anagramMap[sortedStr]) {
            anagramMap[sortedStr] = [];
        }
        
        // Add the original string to the corresponding anagram group
        anagramMap[sortedStr].push(str);
    }

    // Return the grouped anagrams
    return Object.values(anagramMap);
};

