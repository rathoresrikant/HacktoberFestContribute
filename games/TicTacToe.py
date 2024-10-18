import pygame
import random

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
BOTTLE_WIDTH, BOTTLE_HEIGHT = 50, 150
GRAVITY = 0.5
FLIP_FORCE = 15

# Colors
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bottle Flipping Game")

# Load bottle image (make sure to have a bottle image in the same directory)
bottle_image = pygame.Surface((BOTTLE_WIDTH, BOTTLE_HEIGHT))
bottle_image.fill(GREEN)

# Game variables
bottle_x = WIDTH // 2 - BOTTLE_WIDTH // 2
bottle_y = HEIGHT - BOTTLE_HEIGHT
bottle_velocity = 0
is_flipping = False
clock = pygame.time.Clock()

# Game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and not is_flipping:
                bottle_velocity = -FLIP_FORCE
                is_flipping = True

    # Update bottle position
    if is_flipping:
        bottle_velocity += GRAVITY
        bottle_y += bottle_velocity

        # Check if the bottle has landed
        if bottle_y >= HEIGHT - BOTTLE_HEIGHT:
            bottle_y = HEIGHT - BOTTLE_HEIGHT
            if bottle_velocity > 0:  # Bottle landed
                if random.choice([True, False]):  # Randomly decide if it lands upright
                    print("Landed Upright!")
                else:
                    print("Failed to Land Upright!")
            bottle_velocity = 0
            is_flipping = False

    # Fill the screen with white
    screen.fill(WHITE)

    # Draw the bottle
    screen.blit(bottle_image, (bottle_x, bottle_y))

    # Update the display
    pygame.display.flip()
    clock.tick(60)

# Quit Pygame
pygame.quit()
