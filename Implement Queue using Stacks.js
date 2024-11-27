var MyQueue = function() {
    this.stack1 = [];   //push
    this.stack2 = [];   //pop
};

MyQueue.prototype.push = function(x) {
    this.stack1.push(x);
};

MyQueue.prototype.pop = function() {
    if (this.stack2.length === 0) {
        while (this.stack1.length > 0) {
            this.stack2.push(this.stack1.pop());
        }
    }
    return this.stack2.pop();
};

MyQueue.prototype.peek = function() {
    if (this.stack2.length === 0) {
        while (this.stack1.length > 0) {
            this.stack2.push(this.stack1.pop());
        }
    }
    return this.stack2[this.stack2.length - 1];
};

MyQueue.prototype.empty = function() {
    return this.stack1.length === 0 && this.stack2.length === 0;
};
