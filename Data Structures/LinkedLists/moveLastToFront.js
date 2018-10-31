function LinkedList() {
  this.head = undefined
  this.length = 0 
  this.get = function(position) {
    if (position >= this.length) {
      throw new Error('Position is greater than the list range')
    }

    var current = this.head 

    for (var i = 0; i < position; i++) {
      current = current.next
    }

    return current
  }

  this.add = function(value, position) {
    var node = {
      value: value,
      next: undefined
    }

    if (position === 0) {
      node.next = this.head
      this.head = node
    } else {
      var prev = this.get(position - 1)
      console.log('prev', prev)
      var current = prev.next
      node.next = current
      prev.next = node
    }

    this.length++
  }

  this.remove = function(position) {
    if (!this.head) {
      throw new Error('Empty list')
    }

    if (position === 0) {
      this.head = this.head.next
    } else {
      var prev = this.get(position - 1)
      prev.next = prev.next.next
    }

    this.length--
  }

  this.moveToFront = function() {
    if (this.head === undefined || this.head.next === undefined) {
      return 
    }

    var lastNode = {
      value: this.get(this.length - 1).value,
      next: undefined
    }

    lastNode.next = this.head
    this.head = lastNode

    return this
  }
}

var list = new LinkedList()
list.add(2, 0)
list.add(4, 1)
list.add(6, 2)
list.add(8, 3)

console.log('initial list',list)
console.log('list changed', list.moveToFront())

