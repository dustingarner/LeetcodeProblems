var ArrayWrapper = function(nums) {
    this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    for(i of this.nums){
        sum += i;
    }
    return sum;
}

ArrayWrapper.prototype.toString = function() {
    let str = "[";
    for(i in this.nums){
        str = str.concat(this.nums[i].toString());
        if(i<this.nums.length-1){ 
            str = str.concat(",");
        }
    }
    str = str.concat("]");
    return str;
}
