/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const chunked = [];
    let temp = [];
    for(let i=0; i<arr.length; ++i){
        if(i%size==0){
            if(i>0){
                chunked.push(temp);
            }
            temp = [];
        }
        temp.push(arr[i]);
    }
    if(temp.length>0){
        chunked.push(temp);
    }
    return chunked;
};
