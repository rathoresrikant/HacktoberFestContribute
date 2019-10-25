// LinkedList Node
class Node{
  int val;
  Node next;
  
  Node(int x){
    this.val = x;
    this.next = null;
  }
}

class LinkedList{
  Node start;
  int length;
  
  LinkedList([Node n=null]){
    if (n != null) {
      this.start = n;
      this.length = 1;
    }
    else{
      this.start = null;
      this.length = 0;
    }
  }
  
  void insert_end(Node n){
    if (this.start == null){
      this.start = n;
      this.length += 1;
      return;
    }
    Node temp = this.start;
    while (temp.next != null){
      temp = temp.next;
    }
    temp.next = n;
    this.length += 1;
  }
  
  void delete_end(){
    if (this.start == null){
      return;
    }
    
    Node temp = this.start;
    while (temp.next.next != null){
      temp = temp.next;
    }
    temp.next = null;
    this.length -= 1;
  }
  
  void display(){
    Node temp = this.start;
    while (temp != null){
      print(temp.val);
      temp = temp.next;
    }
  }
}

main(){
  LinkedList l = LinkedList();
  l.insert_end(Node(3));
  l.insert_end(Node(5));
  l.insert_end(Node(2));
  l.insert_end(Node(1));
  l.insert_end(Node(7));
  
  l.display();
  
  l.delete_end();
  l.delete_end();
  
  l.display();
}

// This code was contributed by Surya Kant Sahu (https://ojus1.github.io)