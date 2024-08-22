var compactObject = function(obj) {
    if(obj===null){
        return null;
    }
    if(obj instanceof Array){
        let newArr = [];
        for(let i=0; i<obj.length; ++i){
            let comp = compactObject(obj[i]);
            if(comp===null){
                continue;
            }
            newArr.push(comp);
        }
        return newArr;
    }
    else if(obj instanceof Object){
        let newObj = {};
        for(const [key, value] of Object.entries(obj)){
            let comp = compactObject(value);
            if(comp===null){
                continue;
            }
            newObj[key] = comp;
        }
        return newObj;
    }
    else{
        if(Boolean(obj)===false){
            return null;
        }
    }
    return obj;
};
