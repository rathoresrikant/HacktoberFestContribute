''' Football
for each goal scored=20 points
for each foul=10 points deducted
if a player gets negative score, he is considered to have 0 points'''

N=int(input("Enter the no. of players: "))
for i in range(0,N):
	g=int(input("enter the number of goals: "))
	f=int(input("enter the number of fouls: "))
	score=g*20-f*10
	while score<=-1:
		score=0
print("Score of player is: ",score)