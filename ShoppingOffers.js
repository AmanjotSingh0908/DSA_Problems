//Memoization & Unbounded Knapsack
var shoppingOffers = function(price, special, needs, lookup = {}) {
    const needsKey = needs.toString();
    
    if (lookup[needsKey] !== undefined) {
        return lookup[needsKey];
    }
    
    let minPrice = needs.reduce((acc, need, idx) => acc + need * price[idx], 0);

    for (let offer of special) {
        let newNeeds = [...needs];
        let isValid = true;

        for (let i = 0; i < needs.length; i++) {
            if (offer[i] > newNeeds[i]) {
                isValid = false;
                break;
            }
            newNeeds[i] -= offer[i];
        }

        if (isValid) {
            minPrice = Math.min(minPrice, offer[offer.length - 1] + shoppingOffers(price, special, newNeeds, lookup));
        }
    }
    lookup[needsKey] = minPrice;
    return minPrice;
};
