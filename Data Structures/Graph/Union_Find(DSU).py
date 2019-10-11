class Union_Find:
    def __init__(self, tam): #tam eh o tamanho do meu vetor que vai funcionar como union-find
        self.tam = tam
        self.dsu = [n for n in range(0, tam)]
        self.size = [1 for n in range(0, tam)]
        
    def root(self, i): #funcao para pegar a raiz dado um elemento do union-find
        while self.dsu[i] != i:
            self.dsu[i] = self.dsu[self.dsu[i]]
            i = self.dsu[i]
        return i 

    def find(self, a, b):
        A = self.root(a)
        B = self.root(b)
        if A == B:
            return True
        else:
            return False
    
    def union(self, a, b):
        A = self.root(a)
        B = self.root(b)
        if A == B:
            return
        if self.size[A] < self.size[B]:
            self.dsu[A] = self.dsu[B]
            self.size[B] += self.size[A]
        else:
            self.dsu[B] = self.dsu[A]
            self.size[A] += self.size[B]

    def numelements(self, a):
        A = self.root(a)
        return self.size[A]
        
        
def main():
    uf = Union_Find(10)
    print(uf.dsu)
    uf.union(2,3)
    print(uf.dsu)
    print(uf.root(3))
    
if __name__ == '__main__':
    main()
