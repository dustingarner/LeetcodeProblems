/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions, index=0) {
    return function(x) {
        if(functions.length == index){return x;}
        return functions[index](compose(functions, index+1)(x));
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
