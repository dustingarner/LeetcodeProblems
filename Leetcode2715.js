/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    const doFunc = setTimeout(()=>fn(...args), t);
    return (()=>clearTimeout(doFunc));
};

