function Stack() {
  this._items = []

  // if (arguments.length === 1) 

  this.push = function(item) {
    this._items.push(item)
  }

  this.pop = function(count) {
    if (this.isEmpty()) {
      return 
    } else {
      return this._items.pop()
    }
  }

  this.size = function() {
    return this._items.length 
  }

  this.isEmpty = function() {
    return this._items.length === 0
  }
}

function insertAtBottom(stack, item) {
  if (stack.isEmpty()) {
    stack.push(item)
  } else {
    var temp = stack.pop()
    insertAtBottom(stack, item)
    stack.push(temp)
  }
}

function reverse(stack) {
  if (!stack.isEmpty()) {
    var temp = stack.pop()
    reverse(stack)
    insertAtBottom(stack, temp)
  }

  return stack
}

