const max = 100;

class Stack {
  int _topIndex = -1;
  List<int> _data = List(max);
  
  push (value) => _topIndex == max ? 'Stack Overflow' : _data[++_topIndex] = value;
  
  top() => _topIndex == -1 ? 'Empty Stack' : _data[_topIndex];
  
  pop() {
    if (_topIndex == -1) {
      print('Stack Underflow');
    } else {
      _topIndex--;
    }
  } 
  
  
  display() {
    for (int i = _topIndex; i > -1; i--) {
      print(_data[i]);
    }
  }
  
  
  
  
}


void main() {
  Stack s = Stack();
  
  //Pushing few elements on stack
  s.push(10);
  s.push(20);
  s.push(30);
  
 
  //Displaying top (should return 30);
  print(s.top());
  
  //Popping one element from stack
  s.pop();

  //Displaying rest of the elements after popping (20, 10)
  s.display();

  
}
