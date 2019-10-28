import random

def checkValidSuit(s):
	return s in ['H','S','C']
	
def printSuit(s):
	suitNames = {'H': 'Hearts', 'S': 'Spades', 'C': 'Clubs'}
	return suitNames[s]

def chooseSuits():
	hearts   = [range(2:15)]
	spades   = [range(2:15)]
	clubs    = [range(2:15)]
	suits    = {'H': hearts, 'S': spades, 'C': clubs}
	computerSuit = suits[random.choice('H','S','C')]

	while True:
		suit = input("Choose your suit: ('H'earts  'S'pades  'C'lubs): ")
		if(checkValidSuit(suit)):
			printSuit(suit)
			return computerSuit, suit = suits[suit]
		else:
			print("Wrong option! Choose again.")

def main():
	playerScore = 0
	computerScore = 0
	diamonds = [range(2:15)]
	random.shuffle(diamonds)
	print("\n\n" + "*"*45 + " Play Diamond Card Game " + "*"*45 + "\n")
	computerSuit, playerSuit = chooseSuits()


while len(diamonds) > 0:
	diamond = random.choice(diamonds)
	diamonds.remove(diamond)
	print("-"*50)
	print("Diamond for biding is: ", diamond)
	print("-"*50,"\n")
	print("Diamonds left", diamonds)
	print("Cards left with computer: ", spades)
	print("Cards left with you: ", hearts)
	print("\n")
	heart = int(input("\tPick a card from your available cards: "))
	spade = random.choice(spades)
	if(heart > spade):
		playerScore += diamond
	elif(spade > heart):
		computerScore += diamond
	else:
		playerScore += diamond//2
		computerScore += diamond//2
	hearts.remove(heart)
	spades.remove(spade)
	print("\tYour bid: %d, Computer's bid: %d" % (heart, spade))
	print("\t\t\tYour score: ", playerScore)
	print("\t\t\tComputer's score: ", computerScore)
	print("_"*120)
	print("\n")
print("FINAL SCORES:\n\tPlayer's score: %d\n\tComputer's score: %d\n" % (playerScore, computerScore))
if playerScore > computerScore:
	print("\t\t\tYOU WIN")
elif playerScore < computerScore:
	print("\t\t\tCOMPUTER WINS")
else:
	print("\t\t\tIT'S A DRAW")
print("-"*150)








if __name__ == '__main__':
	main()
