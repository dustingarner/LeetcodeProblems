/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let group = {};
    this.forEach((element) => {
        let ans = fn(element);
        if(!(ans in group)){
            group[ans] = [];
        }
        group[ans].push(element);
    });
    return group;
};
