/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timer = null;

    return function(...args) {
        if(timer!=null){
            clearTimeout(timer);
        }
        timer = setTimeout(() => {
            fn(...args);
        }, t);
    }
};
