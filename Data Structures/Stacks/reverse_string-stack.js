function Stack() {
  this._items = []

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

function reverseString(str) {
  var n = str.length
  var stack = new Stack()

  for(var i = 0; i < n; i++) {
    stack.push(str[i])
  }

  str = ''
  
  for (var i = 0; i < n; i++) {
    str += stack.pop()
  }

  return str
} 
