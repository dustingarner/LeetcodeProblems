/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const originalVal = init;
    const increment = function() {
        init++;
        return init;
    }
    const decrement = function() {
        init--;
        return init;
    }
    const reset = function() {
        init = originalVal;
        return init;
    }
    return {increment: increment, decrement: decrement, reset: reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
