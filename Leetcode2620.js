/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let counter = 0;
    return function() {
        let value = n+counter;
        counter++;
        return value;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
