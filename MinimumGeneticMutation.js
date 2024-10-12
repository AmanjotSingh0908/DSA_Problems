var minMutation = function(start, end, bank) {
    let bankSet = new Set(bank);

    if (!bankSet.has(end)) {
        return -1;
    }

    let queue = [[start, 0]];

    let visited = new Set();
    visited.add(start);

    while (queue.length > 0) {
        let [gene, level] = queue.shift();  //Deque

        if (gene === end) {
            return level;
        }
        
        for (let i = 0; i < gene.length; i++) {
            for (let letter of ['A', 'C', 'G', 'T']) {
                let newGene = gene.slice(0, i) + letter + gene.slice(i + 1);  
                if (!visited.has(newGene) && bankSet.has(newGene)) {
                    queue.push([newGene, level + 1]); 
                    visited.add(newGene);  
                }
            }
        }
    }

    return -1;
};
