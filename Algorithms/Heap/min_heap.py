import math

class MinHeap:
	def __init__(self, N):
		self.N = N
		self.tree = [0 for k in range(N)]
		self.key = [0 for k in range(N)]
		self.pos = [-1 for k in range(N)]
		self.heapsize = 0
	
	@staticmethod
	def l(i):
		return 2 * i + 1
	
	@staticmethod
	def r(i):
		return 2 * i + 2

	@staticmethod
	def p(i):
		return math.floor((i - 1) / 2)
	
	def heapify(self, i):
		L = MinHeap.l(i)
		R = MinHeap.r(i)
		smallest = i
		
		if L < self.heapsize and self.tree[L] < self.tree[i]:
			smallest = L
			
		if R < self.heapsize and self.tree[R] < self.tree[smallest]:
			smallest = R
			
		if smallest != i:
			value = self.tree[i]
			index = self.key[i]
			
			self.tree[i] = self.tree[smallest]
			self.key[i] = self.key[smallest]
			self.tree[smallest] = value
			self.key[smallest] = index
			
			# Change positions
			self.pos[self.key[smallest]] = smallest
			self.pos[self.key[i]] = i
			
			self.heapify(smallest)
	
	def add(self, k, v):
		if self.heapsize < self.N:
			i = self.heapsize
			while i > 0 and v < self.tree[MinHeap.p(i)]:
				self.tree[i] = self.tree[MinHeap.p(i)]
				self.key[i] = self.key[MinHeap.p(i)]
				self.pos[self.key[i]] = i
				i = MinHeap.p(i)
				
			self.tree[i] = v
			self.key[i] = k
			self.pos[k] = i
			self.heapsize += 1
	
	def remove(self):
		index = self.key[0]
		self.heapsize -= 1
		self.tree[0] = self.tree[self.heapsize]
		self.key[0] = self.key[self.heapsize]
		self.pos[self.key[0]] = 0
		self.pos[index] = -1
		self.heapify(0)
		return index
	
	def decreaseKey(self, k, v):
		i = self.pos[k]
		while i > 0 and v < self.tree[MinHeap.p(i)]:
			self.tree[i] = self.tree[MinHeap.p(i)]
			self.key[i] = self.key[MinHeap.p(i)]
			self.pos[self.key[i]] = i
			i = MinHeap.p(i)
		
		self.tree[i] = v
		self.key[i] = k
		self.pos[k] = i
	
	def is_empty(self):
		return self.heapsize == 0
	
	def contains(self, k):
		return self.pos[k] != -1
	
	def printTree(self):
		print(self.tree)
		print(self.key)
		print(self.pos)
		print(self.heapsize)
		print()

if __name__ == '__main__':
	heap = MinHeap(5)
	heap.add(1, 1)
	heap.add(2, 2)
	heap.add(3, 6)
	heap.add(4, 5)
	print(heap.remove())
	heap.decreaseKey(3, 1)
	print(heap.remove())




