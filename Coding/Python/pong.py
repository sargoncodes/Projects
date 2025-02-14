import pygame
import random

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
    color = ("black")
    w = 800
    h = 400
window = Window()

# Create text object
class Text():
    fg = ("black")
    bg = ("white")
    size = 50
    location = (window.w // 4, window.h // 2)
    font = pygame.font.SysFont('Arial', size)
    surface = font.render('Press space to start', True, fg, bg)
text = Text()

#TODO Add draw() functions to objects

# Create paddle object
class Paddle():
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    buffer = 10
    w = 15
    h = 150
    speed = 2
    color = ("white")
lPaddle = Paddle(Paddle.buffer, Paddle.buffer)
rPaddle = Paddle(window.w - (Paddle.buffer + Paddle.w), Paddle.buffer)

# Create ball object
class Ball():
    def __init__(self, x, y):
        self.p = (x,y)
        
    r = 30
    speed = 1
    color = ("white")
ball = Ball(window.w // 2, window.h // 2)

# Display window
screen = pygame.display.set_mode((window.w, window.h))
pygame.display.set_caption('Pong')

# Check if window is closed
def check_event():
    global running
    global wait
    
    for event in pygame.event.get(): 
        if event.type == pygame.QUIT: 
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                wait = not wait

# Check if space was pressed
def space_pressed():
    
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                return True
    
    return False

while running:
    # Defined above
    check_event()
    
    # Set FPS
    clock.tick(FPS)
    
    # Set draw order
    screen.fill(window.color)
    
    # Run while paused
    if wait:
        screen.blit(text.surface, text.location)
        pass
    else:
        #TODO Update object positions
        #TODO Draw objects with their draw() functions
        pass
        
    
    # Update display
    pygame.display.flip()

# Clean exit
pygame.quit()