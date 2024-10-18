import pygame
import random

pygame.init()

WIDTH, HEIGHT = 800, 600
FPS = 60
BOTTLE_WIDTH, BOTTLE_HEIGHT = 400, 300
GRAVITY = 0.5
FLIP_FORCE = -15
FLIP_CHANCE = 0.5

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Single Player Bottle Flip Game")

try:
    bottle_image = pygame.transform.scale(pygame.image.load("bottle.png"), (BOTTLE_WIDTH, BOTTLE_HEIGHT))
except pygame.error as e:
    print(f"Unable to load image: {e}")
    pygame.quit()
    exit()

# Load fonts
font_large = pygame.font.SysFont("Arial", 60)
font_medium = pygame.font.SysFont("Arial", 40)
font_small = pygame.font.SysFont("Arial", 30)

def draw_text_with_background(text, font, color, bg_color, position):
    text_surface = font.render(text, True, color)
    text_rect = text_surface.get_rect(center=position)

    # Draw the background rectangle
    bg_rect = pygame.Rect(text_rect.x - 10, text_rect.y - 10, text_rect.width + 20, text_rect.height + 20)
    pygame.draw.rect(screen, bg_color, bg_rect)

    # Draw the text
    screen.blit(text_surface, text_rect)

class Bottle:
    def __init__(self):
        self.x = WIDTH // 2
        self.y = HEIGHT - BOTTLE_HEIGHT
        self.angle = 0
        self.velocity_y = 0
        self.is_flipping = False
        self.has_flipped = False

    def update(self):
        if self.is_flipping:
            self.velocity_y += GRAVITY
            self.y += self.velocity_y
            self.angle += 10
            if self.y >= HEIGHT - BOTTLE_HEIGHT:
                self.y = HEIGHT - BOTTLE_HEIGHT
                self.is_flipping = False
                self.has_flipped = True
                return random.random() < FLIP_CHANCE
        return False

    def flip(self):
        if not self.is_flipping and not self.has_flipped:
            self.is_flipping = True
            self.velocity_y = FLIP_FORCE

    def draw(self):
        rotated_bottle = pygame.transform.rotate(bottle_image, self.angle)
        rect = rotated_bottle.get_rect(center=(self.x, self.y))
        screen.blit(rotated_bottle, rect.topleft)

    def reset(self):
        self.y = HEIGHT - BOTTLE_HEIGHT
        self.angle = 0
        self.velocity_y = 0
        self.is_flipping = False
        self.has_flipped = False

def main():
    clock = pygame.time.Clock()
    bottle = Bottle()
    score = 0
    running = True
    game_over = False

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if not game_over and event.key == pygame.K_RETURN:
                    if not bottle.is_flipping:
                        landed_upright = bottle.flip()
                        if landed_upright:
                            score += 1
                        bottle.has_flipped = True
                
                if game_over and event.key == pygame.K_SPACE:
                    # Reset the game
                    score = 0
                    bottle.reset()
                    game_over = False

        if not game_over:
            screen.fill((135, 206, 250))
            landed_upright = bottle.update()

            if landed_upright:
                score += 1
                bottle.reset()
            elif bottle.has_flipped and not bottle.is_flipping:
                print("The bottle flipped downwards! Game Over.")
                game_over = True  # End the game if the bottle lands downwards

            bottle.draw()
            
            # Draw scores with attractive text
            draw_text_with_background(f"Score: {score}", font_medium, (255, 215, 0), (0, 0, 0, 150), (WIDTH // 2, 50))
            draw_text_with_background("Press Enter to Flip", font_small, (0, 0, 0), (255, 255, 255, 150), (WIDTH // 2, 100))
        else:
            # Game over screen
            screen.fill((135, 206, 250))
            draw_text_with_background("Game Over!", font_large, (255, 0, 0), (0, 0, 0, 150), (WIDTH // 2, HEIGHT // 2 - 50))
            draw_text_with_background(f"Final Score: {score}", font_medium, (255, 215, 0), (0, 0, 0, 150), (WIDTH // 2, HEIGHT // 2))
            draw_text_with_background("Press SPACE to Restart", font_small, (0, 0, 0), (255, 255, 255, 150), (WIDTH // 2, HEIGHT // 2 + 50))

        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()

if __name__ == "__main__":
    main()
