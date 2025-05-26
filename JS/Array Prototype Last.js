/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    return this.length === 0 ? -1 : this[this.length - 1]
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 let n = Array.length;      // ❌ Incorrect: Array is the constructor, not the array instance
return Array[n-1];         // ❌ Incorrect: Accessing a property on the constructor, not the array
use "this", which refers to the array instance on which the method is called.
 */
