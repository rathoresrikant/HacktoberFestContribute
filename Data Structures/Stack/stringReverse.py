
class stack():

    def __init__(self,lst=[]):
        self.list = lst

    def pop(self):
        return self.list.pop()

    def push(self,x):
        self.list.append(x)
    
    def height(self):
        return len(self.list)

string = input("Enter the string: ")

stck = stack(list(string))

outputstck = stack()

while(stck.height()):
    outputstck.push(stck.pop())

outputString = ''.join(outputstck.list)

print("Reversed String: "+outputString)

