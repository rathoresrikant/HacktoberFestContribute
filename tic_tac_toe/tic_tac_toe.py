import pygame
import random
import array as arr

pygame.init()

white = (255, 255, 255)
black = (0, 0, 0)
blue = (100, 149, 255)

a = arr.array('i', [1, 0, 0, 0, 0, 0, 0, 0, 0, 0])
	
display_surf = pygame.display.set_mode((800, 800))
music = True


def new_game():
	run = 1

	display_surf.fill(white)
	gameIcon = pygame.image.load('circles.png')
	play_sound()

	while run:

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
					pygame.quit()
					quit()
			if event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
				x, y = pygame.mouse.get_pos()
				if (x>725 and x<775) and (y>25 and y<75):
					change()

				if (x>75 and x<200) and (y > 600 and y<725):
					setup()

				if (x>600 and x<725) and (y > 600 and y<725):
					pygame.quit()
					quit()
			
		largeText = pygame.font.SysFont("comicsansms", 100)
		TextSurf, TextRect = text_objects("Tic Tac Toe", largeText)
		TextRect.center = ((800 / 2), (400 / 2))
		display_surf.blit(TextSurf, TextRect)
		
		obs = pygame.image.load('button.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [600, 600])
		pygame.display.update()

		obs = pygame.image.load('play.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [75, 600])
		pygame.display.update()

		pygame.display.update()

def setup():

	pygame.display.set_caption('Tic Tac Toe')
	gameIcon = pygame.image.load('circles.png')
	display_surf.fill(white)
	pygame.draw.rect(display_surf, black, (300, 100, 10, 600))
	pygame.draw.rect(display_surf, black, (500, 100, 10, 600))
	pygame.draw.rect(display_surf, black, (100, 300, 600, 10))
	pygame.draw.rect(display_surf, black, (100, 500, 600, 10))
	if music==True:
		soundimgon()
	else:
		soundimgoff()
	pygame.display.update()
	game_loop()

def soundimgon():
	pygame.draw.rect(display_surf, white, (725, 25, 50, 50))
	obs = pygame.image.load('musicon.png')
	obs = pygame.transform.scale(obs, (50, 50))
	obs.convert_alpha()
	display_surf.blit(obs, [725, 25])
	pygame.display.update()

def soundimgoff():
	pygame.draw.rect(display_surf, white, (725, 25, 50, 50))
	obs = pygame.image.load('multimedia.png')
	obs = pygame.transform.scale(obs, (50, 50))
	obs.convert_alpha()
	display_surf.blit(obs, [725, 25])
	pygame.display.update()

def text_objects(text, font):
	textSurface = font.render(text, True, blue)
	return textSurface, textSurface.get_rect()

def paused():
	pause = 1
	while pause:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				quit()
		pygame.display.update()

def mark_x(num):
	if num%3==1:
		x = 150
	
	elif num%3==2:
		x = 350

	elif num%3==0:
		x = 550

	if num<=3:
		y = 150

	elif num<=6 and num>3:
		y = 350

	elif num<=9 and num>6:
		y = 550

	obs = pygame.image.load('interface.png')
	obs = pygame.transform.scale(obs, (125, 125))
	obs.convert_alpha()
	display_surf.blit(obs, [x, y])
	pygame.display.update()	


def mark_o(num):

	if num%3==1:
		x = 150
	
	elif num%3==2:
		x = 350

	elif num%3==0:
		x = 550

	if num<=3:
		y = 150

	elif num<=6 and num>3:
		y = 350

	elif num<=9 and num>6:
		y = 550

	obs = pygame.image.load('shapes.png')
	obs = pygame.transform.scale(obs, (135, 135))
	obs.convert_alpha()
	display_surf.blit(obs, [x, y])
	pygame.display.update()

def lose():
	
	run = 1

	display_surf.fill(white)
	if music==True:
		soundimgon()
	else:
		soundimgoff()

	while run:

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
					pygame.quit()
					quit()
			if event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
				x, y = pygame.mouse.get_pos()
				if (x>725 and x<775) and (y>25 and y<75):
					change()

				if (x>75 and x<200) and (y > 600 and y<725):
					setup()

				if (x>600 and x<725) and (y > 600 and y<725):
					pygame.quit()
					quit()
			
		largeText = pygame.font.SysFont("comicsansms", 100)
		TextSurf, TextRect = text_objects("You Lost", largeText)
		TextRect.center = ((800 / 2), (400 / 2))
		display_surf.blit(TextSurf, TextRect)

		obs = pygame.image.load('feelings.png')
		obs = pygame.transform.scale(obs, (200, 200))
		obs.convert_alpha()
		display_surf.blit(obs, [300, 300])
		pygame.display.update()
		
		obs = pygame.image.load('button.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [600, 600])
		pygame.display.update()

		obs = pygame.image.load('arrows.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [75, 600])
		pygame.display.update()

		pygame.display.update()

def win():

	run = 1
	display_surf.fill(white)
	if music==True:
		soundimgon()
	else:
		soundimgoff()
	
	while run:

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
					pygame.quit()
					quit()
			if event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
				x, y = pygame.mouse.get_pos()
				if (x>725 and x<775) and (y>25 and y<75):
					change()

				if (x>75 and x<200) and (y > 600 and y<725):
					setup()

				if (x>600 and x<725) and (y > 600 and y<725):
					pygame.quit()
					quit()

		largeText = pygame.font.SysFont("comicsansms", 100)
		TextSurf, TextRect = text_objects("You Won", largeText)
		TextRect.center = (400, 200)
		display_surf.blit(TextSurf, TextRect)

		obs = pygame.image.load('happy.jpeg')
		obs = pygame.transform.scale(obs, (200, 200))
		obs.convert_alpha()
		display_surf.blit(obs, [300, 300])
		pygame.display.update()


		obs = pygame.image.load('button.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [600, 600])
		pygame.display.update()

		obs = pygame.image.load('arrows.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [75, 600])
		pygame.display.update()

		pygame.display.update()

def tie():

	run = 1
	display_surf.fill(white)
	if music==True:
		soundimgon()
	else:
		soundimgoff()
	
	while run:

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
					pygame.quit()
					quit()
			if event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
				x, y = pygame.mouse.get_pos()
				if (x>725 and x<775) and (y>25 and y<75):
					change()

				if (x>75 and x<200) and (y > 600 and y<725):
					setup()

				if (x>600 and x<725) and (y > 600 and y<725):
					pygame.quit()
					quit()


		largeText = pygame.font.SysFont("comicsansms", 100)
		TextSurf, TextRect = text_objects("Tie", largeText)
		TextRect.center = ((800 / 2), (400 / 2))
		display_surf.blit(TextSurf, TextRect)

		obs = pygame.image.load('blank.png')
		obs = pygame.transform.scale(obs, (200, 200))
		obs.convert_alpha()
		display_surf.blit(obs, [300, 300])
		pygame.display.update()

		obs = pygame.image.load('button.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [600, 600])
		pygame.display.update()

		obs = pygame.image.load('arrows.png')
		obs = pygame.transform.scale(obs, (125, 125))
		obs.convert_alpha()
		display_surf.blit(obs, [75, 600])
		pygame.display.update()

		pygame.display.update()

def play_sound():
	global music
	music =True
	pygame.mixer.music.load('music1.mp3')
	pygame.mixer.music.play(-1)
	pygame.draw.rect(display_surf, white, (725, 25, 50, 50))
	obs = pygame.image.load('musicon.png')
	obs = pygame.transform.scale(obs, (50, 50))
	obs.convert_alpha()
	display_surf.blit(obs, [725, 25])
	pygame.display.update()

def unmute():
	global music
	music =True
	#pygame.mixer.music.load('music1.mp3')
	pygame.mixer.music.unpause()
	pygame.draw.rect(display_surf, white, (725, 25, 50, 50))
	obs = pygame.image.load('musicon.png')
	obs = pygame.transform.scale(obs, (50, 50))
	obs.convert_alpha()
	display_surf.blit(obs, [725, 25])
	pygame.display.update()

def mute():
	global music
	music = False
	pygame.mixer.music.pause()
	pygame.draw.rect(display_surf, white, (725, 25, 50, 50))
	obs = pygame.image.load('multimedia.png')
	obs = pygame.transform.scale(obs, (50, 50))
	obs.convert_alpha()
	display_surf.blit(obs, [725, 25])
	pygame.display.update()

def change():
	if music==False:
		unmute()
	
	else:
		mute()


def check():

	if a[1] == a[2] and a[2] == a[3]:
		if a[1] == 1:
			pygame.time.delay(500)
			lose()
		elif a[1] == 2:
			pygame.time.delay(500)
			win()

	if a[4] == a[5] and a[5] == a[6]:
		if a[4] == 1:
			pygame.time.delay(500)
			lose()
		elif a[4] == 2:
			pygame.time.delay(500)
			win()

	if a[7] == a[8] and a[8] == a[9]:
		if a[7] == 1:
			pygame.time.delay(500)
			lose()
		elif a[7] == 2:
			pygame.time.delay(500)
			win()					

	if a[1] == a[4] and a[4] == a[7]:
		if a[1] == 1:
			pygame.time.delay(500)
			lose()
		elif a[1] == 2:
			pygame.time.delay(500)
			win()

	if a[2] == a[5] and a[5] == a[8]:
		if a[2] == 1:
			pygame.time.delay(500)
			lose()
		elif a[2] == 2:
			pygame.time.delay(500)
			win()

	if a[3] == a[6] and a[6] == a[9]:
		if a[3] == 1:
			pygame.time.delay(500)
			lose()
		elif a[3] == 2:
			pygame.time.delay(500)
			win()

	if a[1] == a[5] and a[5] == a[9]:
		if a[1] == 1:
			pygame.time.delay(500)
			lose()
		elif a[1] == 2:
			pygame.time.delay(500)
			win()

	if a[3] == a[5] and a[5] == a[7]:
		if a[3] == 1:
			pygame.time.delay(500)
			lose()
		elif a[3] == 2:
			pygame.time.delay(500)
			win()


def game_loop():
	
	a[0] = 1
	a[1] = 0
	a[2] = 0
	a[3] = 0
	a[4] = 0
	a[5] = 0
	a[6] = 0
	a[7] = 0
	a[8] = 0
	a[9] = 0

	run = 1
	k = 0

	gameIcon = pygame.image.load('circles.png')
	
	if music==True:
		soundimgon()
	else:
		soundimgoff()

	while run:

		comp = 0 
		while a[comp]==1 or a[comp]==2:
			comp = random.randint(1, 9)
		
		mark_x(comp)
		a[comp] = 1
		check()

		k = k+1

		if k==9:
			pygame.time.delay(500)
			tie()

		var = 0
		while var==0:

			for event in pygame.event.get():

				if event.type == pygame.QUIT:
					pygame.quit()
					quit()

				if event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
					x, y = pygame.mouse.get_pos()

					if (x>725 and x<775) and (y>25 and y<75):
						change()
				
					if (x<300) and (x>100) and (y<300) and (y>100) and (a[1]==0):
						mark_o(1)
						a[1] = 2
						k = k+1

					elif (x<500) and (x>300) and (y<300) and (y>100) and (a[2]==0):
						mark_o(2)
						a[2] = 2
						k = k+1

					elif (x<700) and (x>500) and (y <300) and (y>100) and (a[3]==0):
						mark_o(3)
						a[3] = 2
						k = k+1

					elif (x<300) and (x >100) and (y < 500) and (y>300) and a[4]==0:
						mark_o(4)
						a[4] = 2
						k = k+1

					elif (x<500) and (x>300) and (y <500) and (y>300) and a[5]==0:
						mark_o(5)
						a[5] = 2
						k = k+1

					elif (x<700) and (x>500) and (y <500) and (y>300) and a[6]==0:
						mark_o(6)
						a[6] = 2
						k = k+1

					elif (x<300) and (x>100) and (y<700) and (y>500) and a[7]==0:
						mark_o(7)
						a[7] = 2
						k = k+1

					elif (x<500) and (x>300) and (y<700) and (y>500) and a[8]==0:
						mark_o(8)
						a[8] = 2
						k = k+1

					elif (x<700) and (x>500) and (y<700) and (y>500) and a[9]==0:
						mark_o(9)
						a[9] = 2
						k = k+1

					else:
						var = 0
						continue

					check()

					var = 1

new_game()

if __name__ == '__main__':
	game_loop()