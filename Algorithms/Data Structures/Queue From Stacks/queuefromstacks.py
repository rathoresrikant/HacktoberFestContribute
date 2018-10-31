class Basic_Stack: # Uses list functions to create a stack
   def __init__(self):
      self.data = [] # Create a list to store the stack

   def push(self, element):
      self.data.append(element) # Push an element to the top of the stack

   def pop(self):
      return self.data.pop() # Pop an element from the top of the stack

   def peek(self):
      return self.data[-1] # Peek at an element from the top of the stack

   def isEmpty(self): # Returns True if the stack is empty, otherwise False
      if len(self.data) == 0:
         return True
      return False

class Queue_From_Stacks:
   def __init__(self): # Create a primary stack to store the data
      self.data = Basic_Stack()

   def enqueue(self, element):
      temp = Basic_Stack() # Create a seconday stack to "flip" the data and maintain queue order
      while(not self.data.isEmpty()): # "flip" the data into the the second stack
         temp.push(self.data.pop())
      self.data.push(element) # push the element to the stack (will now be at the bottom)
      while(not temp.isEmpty()): # push all the elements back on top of the added element
         self.data.push(temp.pop())

   def dequeue(self):
      return self.data.pop() # pop the top element off from the front of the queue

   def isEmpty(self):
      return self.data.isEmpty() # Returns True if the queue is empty, otherwise False
   