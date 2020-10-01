#!/usr/bin/env python3

import random


playing_cards = []



class Card():
    def __init__(self,name,type):
        self.name = name
        self.type = type
        if self.name.isnumeric():
            self.value = int(name)
        elif self.name == "Knight":
            self.value =   11
        elif self.name == "Queen":
            self.value = 12
        elif self.name == "King":
            self.value = 13
        elif self.name == "Ace":
            self.value = 14

    def __str__(self):
        return "Card:\t{}\t\t\tType:\t{}".format(self.name,self.type)

    def compare(self,other):
        if self.value > other.value:
            return "Greater"
        elif self.value < other.value:
            return "Smaller"
        else:
            return "War"


#Called only 1 time per game
class Deck_of_Cards():
    def __init__(self):
        self.numeric = [str(x) for x in range(2,11)]
        self.face = ["Knight","Queen","King","Ace"]
        self.all_sets = []
        self.all_sets.extend(self.numeric)
        self.all_sets.extend(self.face)
        self.types = ["Diamond","Club","Spade","Heart"]
        self.deck = []
        for name in self.all_sets:
            for type in self.types:
                self.deck.append(Card(name,type))

    def __str__(self):
        all_cards = ""
        for card in self.deck:
            all_cards += "{}\n".format(card)
        return all_cards

    def shuffle_cards(self):
        random.shuffle(self.deck)



class Player():
    def __init__(self,name):
          self.name = name
          self.cards_in_hand = []
          self.playing_cards = []

    def __str__(self):
        return "Player:\t{}\t\t\tcontains {} cards".format(self.name,len(self.cards_in_hand))

    def show_card(self,show_status):
        showed_card = self.cards_in_hand.pop(0)
        if show_status == False:
            print("{} put his closed card\n".format(self.name))
        else:
              print("{} showed his card:\n".format(self.name))
              print(showed_card)
              print()
        return showed_card

    def take_cards(self):
        #testing purpose
        file.write(self.name+" takes cards:\n")


        for card in playing_cards:
            self.cards_in_hand.append(card)
            #testing purpose
            file.write("\t\t\t"+card.name+"\t"+card.type+"\n")

        print(self.name + " had a short win!!!")



def welcome_message():
    print("#################################################")
    print("################### !!!!!!!!!!!!!!!!! Welcome to War!!!!!!!!!!#####")
    print("#################################################")
    player1_name = input("Whats's your name warrior? ")
    return player1_name


#3 Closed cards put by each in case of war
def war_declared():
    print("\nWar declared!!\n")
    for i in range(3):
        if player2.cards_in_hand:
            card2 = player2.show_card(False)
            player2.playing_cards.append(card2)
            playing_cards.append(card2)

        if player1.cards_in_hand:
            card1 = player1.show_card(False)
            player1.playing_cards.append(card1)
            playing_cards.append(card1)




        if not player1.cards_in_hand or not player2.cards_in_hand:
                break;

















def play_game():
    for i in "Preparing cards!!!!":
        print(i)

    starter = Deck_of_Cards()
    starter.shuffle_cards()
    global playing_cards
    global player1
    global player2

    player1.cards_in_hand = starter.deck[:26]
    player2.cards_in_hand = starter.deck[26:]
    prev_step_war = False
    while player1.cards_in_hand and player2.cards_in_hand:
        #testing purpose
        file.write("\n\n"+player1.name+"("+str(len(player1.cards_in_hand))+")"+"\t\t\t\t\t\t\t\t"+player2.name+"("+str(len(player2.cards_in_hand))+")"+"\n")
        for i in range(52):
            if(i < len(player1.cards_in_hand)):
                file.write(player1.cards_in_hand[i].name+"\t\t"+player1.cards_in_hand[i].type)
            if(i < len(player2.cards_in_hand)):
                if(i >= len(player1.cards_in_hand)):
                    file.write("\t\t")
                file.write("\t\t\t\t\t\t\t\t"+player2.cards_in_hand[i].name+"\t\t"+player2.cards_in_hand[i].type)
            if(i < len(player1.cards_in_hand) or i < len(player2.cards_in_hand)):
                file.write("\n")

        if prev_step_war == False:
            playing_cards = []
            player1.playing_cards = []
            player2.playing_cards = []
        game_status = input("Enter exit to exit the game and any key to continue or start the game: ")
        if(game_status == "exit"):
            print("Game exited by the user!!!!")
            print("Exiting!!!!!!!!!!!!!!!!!!!!!!")
            break;

        card1 = player1.show_card(True)
        card2 = player2.show_card(True)
        player1.playing_cards.append(card1)
        player2.playing_cards.append(card2)
        playing_cards.append(card2)
        playing_cards.append(card1)


        comparison = player1.playing_cards[-1].compare(player2.playing_cards[-1])
        if comparison == "Greater":
            prev_step_war = False
            player1.take_cards()
        elif comparison == "Smaller":
            prev_step_war = False
            player2.take_cards()
        else:
            war_declared()
            prev_step_war = True
        if player1.cards_in_hand and not player2.cards_in_hand:
            print("{} won the game!!!!!!!!!!!!!!!!!!!!!!".format(player1.name))
        elif player2.cards_in_hand and not player1.cards_in_hand:
            print("{} won the game!!!!!!!!!!!!!!!!!!!!!!".format(player2.name))
        elif not (player1.cards_in_hand or player2.cards_in_hand):
            print("The game ended with a tie!!!!!!!!!!!!!")
    file.close()




player1 = Player(welcome_message())
player2 = Player("Computer")

#testing purpose
file = open("results.txt","w")

play_game()