/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function(mass, asteroids) {
    asteroids.sort(function(a, b){return a - b});
    for(let i  = 0; i < asteroids.length; i++){
        if(mass < asteroids[i]){
            return false;
        } else {
            mass += asteroids[i];
        }
    }
    return true;
};
