/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let min_element = Infinity
    let profit = 0
    for(let i=0; i<prices.length; i++){
            if(prices[i] < min_element){
                min_element = prices[i]
            } else if(prices[i] - min_element > profit){
                profit = prices[i] - min_element
            }
    }
    return profit
};
