/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let obj = {};
    arr1.forEach((element) => {obj[element["id"]] = element;});
    arr2.forEach((element) => {
        let tempId = element["id"]
        if(!(tempId in obj)){
            obj[tempId] = element;
        }
        else{
            for(const [key, value] of Object.entries(element)){
                obj[tempId][key] = value;
            }
        }
    })
    let arr = [];
    for(const [key, value] of Object.entries(obj)){
        arr.push(value);
    }
    return arr.sort((a, b) => a["id"]-b["id"]);
};
