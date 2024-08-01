var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    let hasValue = this.cache.has(key);
    if(hasValue){
        clearTimeout(this.cache.get(key).timer);
    }
    else{
        this.cache.set(key, {});
    }
    this.cache.get(key).value = value;
    this.cache.get(key).timer = setTimeout(()=>{
            this.cache.delete(key);
        }, duration);
    return hasValue;
};

TimeLimitedCache.prototype.get = function(key) {
    let hasValue = this.cache.has(key);
    if(!hasValue){
        return -1;
    }
    return this.cache.get(key).value;
};

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};
