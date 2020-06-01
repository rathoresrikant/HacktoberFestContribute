import pygame
import time
import random
import config
from config import *
from os import path

pygame.init()


def next1():
    button("Player2", 0, 450, 100, 50, green, bright_green, game_loop2)
    pause = True
    paused()


def next2():
    button("Next Level", 100, 450, 100, 50, green, bright_green, game_loop3)
    button("Result", 200, 450, 100, 50, red, bright_red, result)
    pause = True
    paused()


def next3():
    button("Player2", 300, 450, 100, 50, green, bright_green, game_loop4)
    pause = True
    paused()


def next4():
    button("Next Level", 400, 450, 100, 50, green, bright_green, game_loop1)
    button("Result", 500, 450, 100, 50, red, bright_red, result)
    pause = True
    paused()


def score1(count1):
    font = pygame.font.SysFont("comicsansms", 35)
    text = font.render("Player1 score: " + str(count1), True, red)
    gameDisplay.blit(text, (0, 0))


def score2(count2):
    font = pygame.font.SysFont("comicsansms", 35)
    text = font.render("Player2 score: " + str(count2), True, red)
    gameDisplay.blit(text, (0, 0))


def crash2():

    largeText = pygame.font.SysFont("comicsansms", 75)
    TextSurf, TextRect = text_objects("Player crashed", largeText)
    TextRect.center = ((display_width / 2), (display_height / 2))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        button("Next Level", 600, 450, 100, 50, green, bright_green, game_loop3)
        button("Result", 700, 450, 100, 50, red, bright_red, result)

        pygame.display.update()
        clock.tick(15)

def crash4():

    largeText = pygame.font.SysFont("comicsansms", 75)
    TextSurf, TextRect = text_objects("Player crashed", largeText)
    TextRect.center = ((display_width / 2), (display_height / 2))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        button("Next Level", 500, 500, 100, 50, green, bright_green, game_loop1)
        button("Result", 400, 500, 100, 50, red, bright_red, result)
    
        pygame.display.update()
        clock.tick(15)

def crash1():

    largeText = pygame.font.SysFont("comicsansms", 75)
    TextSurf, TextRect = text_objects("Player crashed", largeText)
    TextRect.center = ((display_width / 2), (display_height / 2))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        button("Player 2", 150, 450, 100, 50, green, bright_green, game_loop2)
        pygame.display.update()
        clock.tick(15)


def crash3():

    largeText = pygame.font.SysFont("comicsansms", 75)
    TextSurf, TextRect = text_objects("Player crashed", largeText)
    TextRect.center = ((display_width / 2), (display_height / 2))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        button("Player 2", 100, 450, 100, 50, green, bright_green, game_loop4)
        pygame.display.update()
        clock.tick(15)

def quitgame():
    pygame.quit()
    quit()


def unpause():
    global pause
    pause = False


def paused():

    while pause:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        button("Continue", 150, 450, 100, 50, green, bright_green, unpause)
        button("  ", 550, 450, 100, 50, red, bright_red, result)

        pygame.display.update()
        clock.tick(15)


def game_intro():
    intro = True
    while intro:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()     
        gameDisplay.fill(lightblue)
        largeText = pygame.font.SysFont("comicsansms", 70, "white")
        TextSurf, TextRect = text_objects("River Crossing Competition", largeText)
        TextRect.center = ((display_width / 2), (display_height / 2))
        gameDisplay.blit(TextSurf, TextRect)
        lvl = 0
        button("PLAY", 150, 450, 100, 50, green, bright_green, game_loop1)
        button("  ", 550, 450, 100, 50, lightblue, lightblue, result)

        pygame.display.update()
        clock.tick(15)


def game_loop1():
    global lvl
    global pause
    enemy = random.choice(movingobs)
        #high_score1 = get_high_score1()
    x = (display_width * 0.45)
    y = (display_height * 0.85)
    stone = 0
    x_change = 0
    y_change = 0
    thing_startz = random.randrange(375, 425)
    thing_starty = random.randrange(150, 200)
    thing_startx = -600
    thing_startx1 = -500
    enemy_speed = 4
    thing_width = 55
    thing_height = 95
    # statobs = load_image(statobs.jpeg)
    obs_x= random.randrange(0, 700)
    obs_x1 = random.randrange(0, 700)
    obs_x2 = random.randrange(0, 700)
    obs_x3 = random.randrange(0, display_width)
    obs_x4 = random.randrange(0, display_width)
    obs_y = random.randrange(250, 300)
    
    if obs_x == obs_x1 or obs_x == obs_x2 or obs_x1 == obs_x2:
        obs_x= random.randrange(0, 700)
        obs_x1 = random.randrange(0, 700)
        obs_x2 = random.randrange(0, 700) 

    enemy = random.choice(movingobs)
    enemy1 = random.choice(movingobs)
    thingcount1 = 1
    global dodged1
    gameExit = False
    dodged1 = 0
    while not gameExit:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                if event.key == pygame.K_RIGHT:
                    x_change = 5
                if event.key == pygame.K_p:
                    pause = True
                    paused()
                if event.key == pygame.K_UP:
                	y_change = -5
                if event.key == pygame.K_DOWN:
                	y_change = 5

            if event.type == pygame.KEYUP:
                
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0 
                if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    y_change = 0

        x += x_change
        y += y_change

        gameDisplay.blit(backgroundImage, (0, 0))
        things(enemy, thing_startx, thing_starty, thing_width, thing_height, block_color)
        things(enemy1, thing_startx1, thing_startz, thing_width, thing_height, block_color)
        things(statobs, obs_x, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x1, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x2, obs_y, thing_width, thing_height, block_color)
        thing_startx += enemy_speed
        thing_startx1 += enemy_speed
        if y == 300:
            stone += 3
        car(x, y)
        score1(dodged1 * 10 + stone * 5)

        if x > display_width - car_width or x < 0:
            crash1()
        if y > display_height - car_length or y < 0:
            crash1()

        if thing_startx > display_width:
            thing_startx = 0 - thing_width
            thing_starty = random.randrange(150, 200)
            dodged1 += 1
            enemy = random.choice(movingobs)
            enemy_speed += .25

        if thing_startx1 > display_width:
            thing_startx1 = 0 - thing_width
            thing_startz = random.randrange(375, 425)
            dodged1 += 1
            enemy = random.choice(movingobs)
            enemy_speed += .25

        
        if (x - thing_startx) * (x - thing_startx) + (y - thing_starty) * (y - thing_starty) < 3600:
                time.sleep(.5)
                crash1()

        if (x - thing_startx1) * (x - thing_startx1) + (y - thing_startz) * (y - thing_startz) < 3600:
                time.sleep(.5)
                crash1()

        
        if (x - obs_x) * (x - obs_x) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash1()

        if (x - obs_x1) * (x - obs_x1) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash1()

        if (x - obs_x2) * (x - obs_x2) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash1()
        if y <= 100:
            next1()

        pygame.display.update()
        clock.tick(60)


def game_loop2():
    global pause
    enemy = random.choice(movingobs)

    x = (display_width * 0.45)
    y = (display_height * 0.1)

    x_change = 0
    y_change = 0
    stone = 0
    thing_startz = random.randrange(375, 425)
    thing_starty = random.randrange(150, 200)
    thing_startx = -600
    thing_startx1 = -500
    enemy_speed = 4
    thing_width = 55
    thing_height = 95

    obs_x = random.randrange(0, 700)
    obs_x1 = random.randrange(0, 700)
    obs_x2 = random.randrange(0, 700)
    obs_x3 = random.randrange(0, 700)
    obs_x4 = random.randrange(0, 700)
    obs_y = random.randrange(250, 300)


    if obs_x == obs_x1 or obs_x == obs_x2 or obs_x1 == obs_x2:
        obs_x = random.randrange(0, 700)
        obs_x1 = random.randrange(0, 700)
        obs_x2 = random.randrange(0, 700) 

    enemy = random.choice(movingobs)
    enemy1 = random.choice(movingobs)
    thingcount1 = 1
    global dodged2
    gameExit = False
    dodged2 = 0
    while not gameExit:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                if event.key == pygame.K_RIGHT:
                    x_change = 5
                if event.key == pygame.K_p:
                    pause = True
                    paused()
                if event.key == pygame.K_UP:
                    y_change = -5
                if event.key == pygame.K_DOWN:
                    y_change = 5

            if event.type == pygame.KEYUP:
                
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0 
                if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    y_change = 0

        x += x_change
        y += y_change

        gameDisplay.blit(backgroundImage, (0, 0))

        things(enemy, thing_startx, thing_starty, thing_width, thing_height, block_color) #place enemy
        things(enemy1, thing_startx1, thing_startz, thing_width, thing_height, block_color)
        things(statobs, obs_x, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x1, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x2, obs_y, thing_width, thing_height, block_color)

        thing_startx += enemy_speed 
        thing_startx1 += enemy_speed# Move enemies closer to top of screen
        if y == 300:
            stone += 3
        car(x, y)
        score2(dodged2 * 10 + stone * 5)

        if x > display_width - car_width or x < 0:  # crash if hit the edge of screen
            crash2()
        if y > display_height - car_length or y < 0:  # crash if hit the edge of screen
            crash2()

        # adds score, increase difficulty
        if thing_startx > display_width:
            thing_startx = 0 - thing_width
            thing_starty = random.randrange(150, 200)
            dodged2 += 1
            enemy = random.choice(movingobs)
            enemy_speed += .25

        if thing_startx1 > display_width:
            thing_startx1 = 0 - thing_width
            thing_startz = random.randrange(375, 425)
            dodged2 += 1
            enemy = random.choice(movingobs)
            enemy_speed +=.25

        if (x - thing_startx) * (x - thing_startx) + (y - thing_starty) * (y - thing_starty) < 3600:
                time.sleep(.5)
                crash2()

        if (x - thing_startx1) * (x - thing_startx1) + (y - thing_startz) * (y - thing_startz) < 3600:
                time.sleep(.5)
                crash2()

        
        if (x - obs_x) * (x - obs_x) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash2()

        if (x - obs_x1) * (x - obs_x1) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash2()

        if (x - obs_x2) * (x - obs_x2) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash2()

        if y >= 500:
            next2()

           #  if y > thing_starty and x < thing_starty + thing_height or y + car_length > thing_starty and y + car_length < thing_starty + thing_height:
            #    time.sleep(.5)
             #   crash2() 
    
        pygame.display.update()
        clock.tick(60)


def result():

    if(dodged1 > dodged2):
        winner = "Player1"
    elif(dodged2 > dodged1):
        winner = "Player2"
    else:
        winner = "Player1 and Player2"

    gameDisplay.fill(lightblue)
    largeText = pygame.font.SysFont("comicsansms", 60, "white")
    TextSurf, TextRect = text_objects("Winner: "+str(winner), largeText)
    TextRect.center = ((display_width / 2), (display_height / 2))
    gameDisplay.blit(TextSurf, TextRect)
    # button("Restart", 500, 400, 100, 50, green, bright_green, game_intro)
    
    pygame.display.update()
    clock.tick(15)
    

def game_loop3():
    global pause
    enemy = random.choice(movingobs)
  #  lvl = lvl+1
    x = (display_width * 0.45)
    y = (display_height * 0.1)
    stone = 0
    x_change = 0
    y_change = 0
    thing_startz = random.randrange(375, 425)
    thing_starty = random.randrange(150, 200)
    thing_startx = -600
    thing_startx1 = -500
    enemy_speed = 4
    thing_width = 55
    thing_height = 95
    obs_x = random.randrange(0, 700)
    obs_x1 = random.randrange(0, 700)
    obs_x2 = random.randrange(0, 700)
    obs_y = random.randrange(250, 300)


    if obs_x == obs_x1 or obs_x == obs_x2 or obs_x1 == obs_x2:
        obs_x = random.randrange(0, 700)
        obs_x1 = random.randrange(0, 700)
        obs_x2 = random.randrange(0, 700) 


    enemy = random.choice(movingobs)
    enemy1 = random.choice(movingobs)
    thingcount1 = 1
    gameExit = False
    dodged1 = 0
    while not gameExit:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                if event.key == pygame.K_RIGHT:
                    x_change = 5
                if event.key == pygame.K_p:
                    pause = True
                    paused()
                if event.key == pygame.K_UP:
                    y_change = -5
                if event.key == pygame.K_DOWN:
                    y_change = 5

            if event.type == pygame.KEYUP:
                
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0 
                if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    y_change = 0

        x += x_change
        y += y_change

        gameDisplay.blit(backgroundImage, (0, 0))

        things(enemy, thing_startx, thing_starty, thing_width, thing_height, block_color) #place enemy
        things(enemy1, thing_startx1, thing_startz, thing_width, thing_height, block_color)
        things(statobs, obs_x, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x1, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x2, obs_y, thing_width, thing_height, block_color)
        # things(statobs, obs_x3, obs_y, thing_width, thing_height, block_color)
        # things(statobs, obs_x4, obs_y, thing_width, thing_height, block_color)
        if y == 300:
            stone += 3
        thing_startx += enemy_speed 
        thing_startx1 += enemy_speed
         # Move enemies closer to top of screen
        car(x, y)
        score1(dodged1 * 10 + stone * 5)

        if x > display_width - car_width or x < 0:  # crash if hit the edge of screen
            crash3()
        if y > display_height - car_length or y < 0:  # crash if hit the edge of screen
            crash3()

        # adds score, increase difficulty
        if thing_startx > display_width:
            thing_startx = 0 - thing_width
            thing_starty = random.randrange(150,200)
            dodged1 += 1
            enemy = random.choice(movingobs)
            enemy_speed += .25

        if thing_startx1 > display_width:
            thing_startx1 = 0 - thing_width
            thing_startz = random.randrange(375, 425)
            dodged1 += 1
            enemy = random.choice(movingobs)
            enemy_speed +=.25

        if (x - thing_startx) * (x - thing_startx) + (y - thing_starty) * (y - thing_starty) < 3600:
                time.sleep(.5)
                crash3()

        if (x - thing_startx1) * (x - thing_startx1) + (y - thing_startz) * (y - thing_startz) < 3600:
                time.sleep(.5)
                crash3()

        
        if (x - obs_x) * (x - obs_x) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash3()

        if (x - obs_x1) * (x - obs_x1) + (y - obs_y)*(y - obs_y) < 3600:
            time.sleep(.5)
            crash3()

        if (x - obs_x2) * (x - obs_x2) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash3()

        if y >= 500:
            next3()

    
        pygame.display.update()
        clock.tick(60)

def game_loop4():
    global pause
    enemy = random.choice(movingobs)

    x = (display_width * 0.45)
    y = (display_height * 0.85)
    stone = 0
    x_change = 0
    y_change = 0
    thing_startz = random.randrange(375, 425)
    thing_starty = random.randrange(150, 200)
    thing_startx = -600
    thing_startx1 = -500
    enemy_speed = 4
    thing_width = 55
    thing_height = 95

    obs_x = random.randrange(0, 700)
    obs_x1 = random.randrange(0, 700)
    obs_x2 = random.randrange(0, 700)
    obs_x3 = random.randrange(0, 700)
    obs_x4 = random.randrange(0, display_width)
    obs_y = random.randrange(250, 300)


    if obs_x == obs_x1 or obs_x1 == obs_x2 or obs_x2 == obs_x:
        obs_x = random.randrange(0, 700)
        obs_x1 = random.randrange(0, 700)
        obs_x2 = random.randrange(0, 700)


    enemy = random.choice(movingobs)
    enemy1 = random.choice(movingobs)
    thingcount1 = 1
    gameExit = False
    dodged2 = 0
    while not gameExit:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                if event.key == pygame.K_RIGHT:
                    x_change = 5
                if event.key == pygame.K_p:
                    pause = True
                    paused()
                if event.key == pygame.K_UP:
                    y_change = -5
                if event.key == pygame.K_DOWN:
                    y_change = 5

            if event.type == pygame.KEYUP:
                
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0 
                if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    y_change = 0

        x += x_change
        y += y_change

        gameDisplay.blit(backgroundImage, (0, 0))

        things(enemy, thing_startx, thing_starty, thing_width, thing_height, block_color) #place enemy
        things(enemy1, thing_startx1, thing_startz, thing_width, thing_height, block_color)

        things(statobs, obs_x, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x1, obs_y, thing_width, thing_height, block_color)
        things(statobs, obs_x2, obs_y, thing_width, thing_height, block_color)
        # things(statobs, obs_x3, obs_y, thing_width, thing_height, block_color)
        # things(statobs, obs_x4, obs_y, thing_width, thing_height, block_color)

        thing_startx += enemy_speed
        thing_startx1 += enemy_speed  # Move enemies closer to top of screen
        if y == 300:
            stone += 3
        car(x, y)
        score2(dodged2 * 10 + stone * 5)

        if x > display_width - car_width or x < 0:  # crash if hit the edge of screen
            crash4()
        if y > display_height - car_length or y < 0:  # crash if hit the edge of screen
            crash4()

        # adds score, increase difficulty
        if thing_startx > display_width:
            thing_startx = 0 - thing_width
            thing_starty = random.randrange(150, 200)
            dodged2 += 1
            enemy = random.choice(movingobs)
            enemy_speed += .25

        if thing_startx1 > display_width:
            thing_startx1 = 0 - thing_width
            thing_startz = random.randrange(375, 425)
            dodged2 += 1
            enemy = random.choice(movingobs)
            enemy_speed +=.25

        if (x - thing_startx) * (x - thing_startx) + (y - thing_starty) * (y - thing_starty) < 3600:
                time.sleep(.5)
                crash4()

        if (x - thing_startx1) * (x - thing_startx1) + (y - thing_startz) * (y - thing_startz) < 3600:
                time.sleep(.5)
                crash4()

        
        if (x - obs_x) * (x - obs_x) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash4()

        if (x - obs_x1) * (x - obs_x1) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash4()

        if (x - obs_x2) * (x - obs_x2) + (y - obs_y) * (y - obs_y) < 3600:
            time.sleep(.5)
            crash4()
        if y <= 100:
            next4()

        pygame.display.update()
        clock.tick(60)


game_intro()
game_loop()
pygame.quit()
quit()
