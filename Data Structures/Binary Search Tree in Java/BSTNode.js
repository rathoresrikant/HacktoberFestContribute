class BSTNode{
  constructor(key, val)
    this.value = val;
    this.key = key;
    this.leftNode = null;
    this.rightNode = null;
    this.nodeCount = 0;
  }
  
  getNodeCount(){
    return this.nodeCount;
  }
  
  getValue(){
    return this.value;
  }
  
  getKey(){
    return this.key;
  }
  
  getLeft(){
    return this.leftNode;
  }
  
  getRight(){
    return this.rightNode;
  }
  
  setNodeCount(num){
    if(!Number.isInteger(num))
      throw new Error('Node count must be int');
    this.nodeCount = num;
  }
  
  setValue(val){
    this.value = val;
  }
  
  setKey(key){
    this.key = key;
  }
  
  setLeft(node){
    if(!(node instanceof BSTNode))
      throw new Error('Not a BST Node');
    this.leftNode = node;
  }
  
  setRight(node){
    if(!(node instanceof BSTNode))
      throw new Error('Not a BST Node.');
    this.rightNode = node;
  }
}
