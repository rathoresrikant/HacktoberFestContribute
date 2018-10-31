class Pilha(object):
    def __init__(self):
        self.dados = []
 
    def empilha(self, elemento):
        self.dados.append(elemento)
 
    def desempilha(self):
        if not self.vazia():
            return self.dados.pop(-1)
 
    def vazia(self):
        return len(self.dados) == 0


p = Pilha()

word = raw_input("Insert your string: ")

cont = 0
while(word.__len__() > cont):
    p.empilha(word[cont])
    cont += 1

while(not(p.vazia())):
    print p.desempilha()