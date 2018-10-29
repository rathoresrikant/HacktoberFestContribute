
//Queue implm. using 2 stacks
class StackQueue {
  constructor() {
    this.enqueueStack = [];
    this.dequeueStack = [];
    this.size = 0;
    this.lastOper = 1;
  }
  
  enqueue(data) {
    if(this.lastOper == 0){
      this.deqToEnq();
      this.lastOper = 1;
    }
    this.size++;
    this.enqueueStack.push(data);
  }
  
  dequeue() {
    if(this.lastOper == 1){
      this.enqToDeq();
      this.lastOper = 0;
    }
    if(this.howBig() == 0){
      return null;
    }
    this.size--;
    return this.dequeueStack.pop();
  }
  
  deqToEnq() {
     //Move dequeue to enqueue;
    for(let i = 0; i < this.size; i++) {
      this.enqueueStack.push(this.dequeueStack.pop());
    }
  }
  
  enqToDeq(){
    //Move enqueue to dequeue
    for(let i = 0; i < this.size; i++){
      this.dequeueStack.push(this.enqueueStack.pop());
    }
  }
  
  howBig(){
    return this.size;
  }
}
