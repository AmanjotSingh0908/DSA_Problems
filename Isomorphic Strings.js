var isIsomorphic = function(s, t) {
    if (s.length !== t.length) {
        return false; 
    }
    
    let mapS = new Map(); 
    let mapT = new Map();
    
    for (let i = 0; i < s.length; i++) {
        let charS = s[i];
        let charT = t[i];
      
        if (mapS.has(charS)) {
            if (mapS.get(charS) !== charT) {
                return false; // If the mapping doesn't match, it's not isomorphic.
            }
        } else {
            mapS.set(charS, charT); 
        }


        if (mapT.has(charT)) {
            if (mapT.get(charT) !== charS) {
                return false; // If the mapping doesn't match, it's not isomorphic.
            }
        } else {
            mapT.set(charT, charS); 
        }
    }

    return true; 
};
