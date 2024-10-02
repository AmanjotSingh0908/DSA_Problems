//Approach1
var mergeAlternately = function(word1, word2) {
    let temp = ''; 
    let i = 0, j = 0; 
    while (i < word1.length || j < word2.length) {
        // Add a character from word1 if there is any left
        if (i < word1.length) {
            temp += word1[i];
            i++;
        }
        // Add a character from word2 if there any left
        if (j < word2.length) {
            temp += word2[j];
            j++;
        }
    }

    return temp;
};

//Approach2 [beats 80% on Runtime]
var mergeAlternately = function(word1, word2) {
    let temp = ''; // Result string
    let len1 = word1.length, len2 = word2.length; 
    let i = 0; 
    
    while (i < len1 && i < len2) {
        temp += word1[i] + word2[i]; 
        i++;
    }

    if (i < len1) temp += word1.slice(i); 
    if (i < len2) temp += word2.slice(i); 

    return temp;
};

//Approach3 [Beats 98% on Memory]
var mergeAlternately = function(word1, word2) {
    let result = []; 
    let len1 = word1.length, len2 = word2.length;
    let i = 0, j = 0;
   
    while (i < len1 && j < len2) {
        result.push(word1[i++], word2[j++]); 
    }

    while (i < len1) {
        result.push(word1[i++]);
    }
    while (j < len2) {
        result.push(word2[j++]);
    }

    return result.join('');
};

//Approach4 [Beats 99.2% on Memory]
var mergeAlternately = function(word1, word2) {
let result = ''; 
    let i = 0;
    let len1 = word1.length, len2 = word2.length;

    while (i < len1 || i < len2) {
        if (i < len1) result += word1[i]; 
        if (i < len2) result += word2[i]; 
        i++;
    }
    return result;
};
