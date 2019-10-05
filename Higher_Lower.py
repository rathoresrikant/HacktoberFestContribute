#!/usr/bin/env python3

import random

number = random.randint(1, 10)
tries = 0
win = False # setting a win flag to false


name = input("Hello, What is your username?")

print("Hello " + name + "." )

question = input("Would you like to play a game? [Y/N] ")
if question.lower() == "n": #in case of capital letters is entered
    print("oh..okay")
    exit()
if question.lower() == "y":
    print("I'm thinking of a number between 1 & 10")
while not win:       # while the win is not true, run the while loop. We set win to false at the start therefore this will always run
    guess = int(input("Have a guess: "))
    tries = tries + 1
    if guess == number:
        win = True    # set win to true when the user guesses correctly.
    elif guess < number:
        print("Guess Higher")
    elif guess > number:
        print("Guess Lower")
# if win is true then output message
print("Congrats, you guessed correctly. The number was indeed {}".format(number))
print("it had taken you {} tries".format(tries))