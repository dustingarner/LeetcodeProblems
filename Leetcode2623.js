/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let map = new Map();
    return function(...args) {
            let argCount = arguments.length;
            let currentCount = 0;
            let currentMap = map;
            for(let i=0; i<argCount; ++i){
                if(i == argCount-1 && currentMap.has(arguments[i])){
                    return currentMap.get(arguments[i]);
                }
                if(!currentMap.has(arguments[i])){break;}
                currentMap = currentMap.get(arguments[i]);
            }
            let value = fn(...args);
            currentMap = map;
            for(let i=0; i<argCount; ++i){
                if(i == argCount-1){
                    currentMap.set(arguments[i], value);
                    break;
                }
                if(!currentMap.has(arguments[i])){
                    currentMap.set(arguments[i], new Map());
                }
                currentMap = currentMap.get(arguments[i]);
            }
            return value;
        }
    }


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
