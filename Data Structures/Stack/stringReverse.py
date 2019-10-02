
class stack():

    def __init__(self,string=""):
        self.string = string

    def pop(self):
        self.string = self.string[:-1]

    def top(self):
        return self.string[-1]

    def push(self,x):
        self.string += x
    
    def height(self):
        return len(self.string)

string = input("Enter the string: ")

stck = stack(string)

outputstck = stack()

while(stck.height()):
    outputstck.push(stck.top())
    stck.pop()

outputString = outputstck.string

print("Reversed String: "+outputString)

