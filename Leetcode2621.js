/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    let a = new Promise((resolve, reject) => {
        setTimeout(resolve, millis);
    });
    return a;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
