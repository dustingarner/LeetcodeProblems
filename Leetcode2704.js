/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    const toBe = function(newVal) {
        if(val !== newVal){
            throw "Not Equal";
        }
        return true;
    }
    const notToBe = function(newVal) {
        if(val === newVal){
            throw "Equal";
        }
        return true;
    }
    const expected = {toBe: toBe, notToBe: notToBe};
    return expected;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
