import pygame
pygame.init()

display_width = 800
display_height = 600

black = (0, 0, 0)
white = (255, 255, 255)
red = (200, 0, 0)
green = (0, 200, 0)
bright_red = (255, 0, 0)
bright_green = (0, 255, 0)
block_color = (53, 115, 255)
lightblue = (190, 190, 255)
car_width = 55
car_length = 65

gameDisplay = pygame.display.set_mode((display_width, display_height))
pygame.display.set_caption('River Crossing Competition')
clock = pygame.time.Clock()
gameIcon = pygame.image.load('gameicon.jpg')


backgroundImage = pygame.image.load("background.jpeg")
backgroundImage = pygame.transform.scale(backgroundImage, (800, 600))
gameDisplay.blit(backgroundImage, (0, 0))


pygame.display.set_icon(gameIcon)

pause = False


lvl=0

def next1():
    button("Player2", 0, 450, 100, 50, green, bright_green, game_loop2)
    pause=True
    paused()


def next2():
    button("Next Level", 100, 450, 100, 50, green, bright_green, game_loop3)
    button("Result", 200, 450, 100, 50, red, bright_red, result) 
    pause=True
    paused()


def next3():
    button("Player2", 300, 450, 100, 50, green, bright_green, game_loop4)
    pause=True
    paused()


def next4():
    button("Next Level", 400, 450, 100, 50, green, bright_green, game_loop1)
    button("Result", 500, 450, 100, 50, red, bright_red, result) 
    pause=True
    paused()

def score1(count1):
    font = pygame.font.SysFont("comicsansms", 35) 
    text = font.render("Player1 score: " + str(count1), True, red)
    gameDisplay.blit(text, (0, 0))
    text = font.render("Level: " + str(lvl), True, red)
    gameDisplay.blit(text, (300, 0))


def score2(count2):
    font = pygame.font.SysFont("comicsansms", 35) 
    text = font.render("Player2 score: " + str(count2), True, red)
    gameDisplay.blit(text, (0, 0))
    text = font.render("Level: " + str(lvl), True, red)
    gameDisplay.blit(text, (300, 0))
def load_image(name_img):
    obs = pygame.image.load(name_img)
    obs = pygame.transform.scale(obs, (60, 60))
    return obs.convert_alpha()


def load_image1(name_img):
    obs = pygame.image.load(name_img)
    obs = pygame.transform.scale(obs, (60, 60))
    return obs.convert_alpha()

statobs = load_image1('weather.png')
carImg = load_image('pirate.png')
enemies_list = ['ocean-transportation.png', 'boat.png', 'ship__4_.png', 'ship_1_.png'] # add all other cars
movingobs = [load_image(img) for img in enemies_list]

def things(enemy, thingx, thingy, thingw, thingh, color):
    gameDisplay.blit(enemy, [thingx, thingy, thingw, thingh])


def car(x, y):
    gameDisplay.blit(carImg, (x, y))



def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()
def button(msg, x, y, w, h, ic, ac, action=None):
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()

    if x + w > mouse[0] > x and y + h > mouse[1] > y:
        pygame.draw.rect(gameDisplay, ac, (x, y, w, h))
        if click[0] == 1 and action != None:
            action()
    else:
        pygame.draw.rect(gameDisplay, ic, (x, y, w, h))
    smallText = pygame.font.SysFont("comicsansms", 20)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ((x + (w / 2)), (y + (h / 2)))
    gameDisplay.blit(textSurf, textRect)
