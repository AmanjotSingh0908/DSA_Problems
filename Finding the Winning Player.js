//Game Theory
/**
 * @param {number} x
 * @param {number} y
 * @return {string}
 */
var winningPlayer = function(x, y) {
     let turn = 0; 

    while (x > 0 && y >= 4) {
        x--;
        y -= 4;

        turn = 1 - turn;
    }

    return turn == 0 ? "Bob" : "Alice";
};
