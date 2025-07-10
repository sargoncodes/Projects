import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Setup FPS
clock = pygame.time.Clock()
FPS = 60

# Define gamestate variables
wait = True
running = True

# Create window object
class Window():
    bg_color = (0, 0, 0) # Black
    line_color = (50, 50, 50) # Dark grey
    w = 600
    h = 600
    square = 30
    surface = pygame.display.set_mode((w, h))
    caption = pygame.display.set_caption('Snake Game')

    def draw_grid(self):
        for x in range(0, window.w, self.square):
            for y in range(0, window.h, self.square):
                rect = pygame.Rect(x, y, self.square, self.square)
                pygame.draw.rect(window.surface, window.line_color, rect, 1)
                
window = Window()

class Candy():
    def __init__(self):
        self.x = random.randint(0, window.w - window.square)
        self.y = random.randint(0, window.h - window.square)
        self.color = (255, 0, 0) # Red

    def draw(self):
        pygame.draw.rect(window.surface, self.color, (self.x, self.y, window.square, window.square))

candy = Candy()

def check_keys():
    global running
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

# Main game loop
running = True
while running:
    # Set FPS
    clock.tick(FPS)
    
    # Check input
    check_keys()

    # Set drawing order
    window.surface.fill(window.bg_color)
    window.draw_grid()
    candy.draw()

    # Update the display
    pygame.display.flip()

# Quit Pygame
pygame.quit()
sys.exit()
