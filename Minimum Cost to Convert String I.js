/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function(source, target, original, changed, cost) {
    const dist = Array.from({ length: 26 }, () => Array(26).fill(Infinity));    //lowercase characters are 26

    //Initialise distance matrix with direct conversion costs
    for(let i = 0; i < 26; i++){
        dist[i][i] = 0;
    }

    for(let i = 0; i < original.length; i++){
        const from = original[i].charCodeAt(0) - 'a'.charCodeAt(0); //a represented by 0
        const to = changed[i].charCodeAt(0) - 'a'.charCodeAt(0);
        dist[from][to] = Math.min(dist[from][to], cost[i]);
    }

    ////Floyd-Warshall Algorithm to compute minimum costs b/w all pairs
    for(let node = 0; node < 26; node++){
        for(let u =0; u < 26; u++){
            for(let v = 0; v<26; v++){
                if(u==v) continue;
                dist[u][v] = Math.min(dist[u][v], dist[u][node] + dist[node][v]);
            }
        }
    }
    
    let totalCost = 0;
    for(let i =0; i < source.length; i++){
        const from = source[i].charCodeAt(0) - 'a'.charCodeAt(0);
        const to = target[i].charCodeAt(0) - 'a'.charCodeAt(0);

        if(dist[from][to] === Infinity) {
            return -1;
        }

        totalCost += dist[from][to];
    }

    return totalCost;
};
