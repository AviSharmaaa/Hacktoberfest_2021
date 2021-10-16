export class LinkedList {

    constructor(){
      this.list = [];
    }
    push(item) {
      this.list.push(item);
    }
  
    pop() {
      if (this.list.length > 0) {
        return this.list.pop();
      }
    }
  
    shift() {
      if (this.list.length > 0) {
        return this.list.shift();
      }
    }
  
    unshift(item) {
        return this.list.unshift(item);
    }
  
    delete(item) {
      if (item !== undefined) {
        if (this.list.indexOf(item)>=0) this.list.splice(this.list.indexOf(item), 1);
      }
    }
  
    count() {
      return this.list.length;
    }
  }
  