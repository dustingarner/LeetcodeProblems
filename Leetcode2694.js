class EventEmitter {
    constructor(){
        this.listeners = {};
    }

    subscribe(eventName, callback) {
        if(!(eventName in this.listeners)){
            this.listeners[eventName] = [];
        }
        this.listeners[eventName].push(callback);

        return {
            unsubscribe: () => {
                this.listeners[eventName] = this.listeners[eventName].filter((func) => func!==callback);
            }
        };
    }
    
    emit(eventName, args = []) {
        if(!(eventName in this.listeners)){
            return [];
        }
        return this.listeners[eventName].map((x) => x(...args));
    }
}
