/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    let answers = new Array(functions.length).fill(0);
    let resolveCount = 0;
    return new Promise((resolve, reject) => {
        for(let i=0; i<functions.length; ++i){
            let value = i;
            functions[i]().then((success) => {
                answers[value] = success;
                resolveCount += 1;
                if(resolveCount==answers.length){
                    resolve(answers);
                }
            }).catch((fail) => {reject("Error");});
        }
    })
};
