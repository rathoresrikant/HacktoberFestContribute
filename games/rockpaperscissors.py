import random
start = True
l = 0
w = 0
t = 0
print("Bot is ready to be used")
while start == True:
    userinput = input("Choose Rock, Paper, Or scissors ").lower()
    randomnumber = random.randint(1, 3)
    #1 = rock
    #2 = paper
    #3 = scissors
    if randomnumber == 1:
        computerai = "rock"
    if randomnumber == 2:
        computerai = "paper"
    if randomnumber == 3:
        computerai = "scissors"
    print("The computer chose", computerai)
    if userinput == computerai:
        print("Its a tie!!")
        t += 1
        print("Losses:", l)
        print("Victorys:", w)
        print("Ties:", t)
    elif userinput == "rock" and computerai == "scissors":
        print("You Won!!")
        w += 1
        print("Losses:", l)
        print("Victorys:", w)
        print("Ties:", t)
    elif userinput == "paper" and computerai == "rock":
        print("You Won!!")
        w += 1
        print("Losses:", l)
        print("Victorys:", w)
        print("Ties:", t)
    elif userinput == "scissors" and computerai == "paper":

        print("You Won!!")
        w += 1
        print("Losses:", l)
        print("Victorys:", w)
        print("Ties:", t)
    else:
        print("You Lost!!")
        l += 1
        print("Losses:", l)
        print("Victorys:", w)
        print("Ties:", t)
    again = input("Do you want to play again(y/n)").lower()
    if again == "n":
        print("Thanks for playing!")
        start = False
    else:
        start = True
